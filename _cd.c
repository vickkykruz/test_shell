#include "shell.h"
/**
 * set_directory - This is a function thatreturn the set directory
 * @ptr: This is an argument that represent the data_list struct
 * @dir: This is an argument that represent the path of the working dir
 * 
 * Rteurn: This function return (0) as sucess otherwise (-1) as error
*/
integer set_directory(data_list *ptr, string dir)
{
    integer err_code = 0;
    char buff[128] = {0};

    getcwd(buff, 128);

    if (_strcomp(buff, dir, 0) != NULL)
    {
        err_code = chdir(dir);
        if (err_code == -1)
        {
            errno = 2;
            return (3);
        }
        set_env("PWD", dir, ptr);
    }
    set_env("OLDPWD", buff, ptr);
    return (0);
}
/**
 * _cd - This is a function that return the changed current directory
 * @ptr: This is an argument that represent the data_list struct
 * 
 * Return: This function return (0) as success otherwise (-1) as error
*/
integer _cd(data_list *ptr)
{
    char buff[128] = {0};
    string ptr_home = access_env_key("HOME", ptr);
    integer err_code = 0;
    string ptr_old = NULL;

    if (ptr->segment[1])
    {
        if (_strcomp(ptr->segment[1], "-", 0))
        {
            ptr_old = access_env_key("OLDPWD", ptr);
            if (ptr_old)
                err_code = set_directory(ptr, ptr_old);
            print(access_env_key("PWD", ptr));
            print("\n");
            return (err_code);
        }
        else
        {
            return (set_directory(ptr, ptr->segment[1]));
        }
    }
    else
    {
        if (!ptr_home)
            ptr_home = getcwd(buff, 128);

        return (set_directory(ptr, ptr_home));
    }
    return (0);
}