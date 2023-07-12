#include "shell.h"
/**
 * _exit - This is a function that return that exit status of the program
 * @ptr: This is an argument that represent the data_list sturct
 * 
 * Return: This function return (0) as success othwise (-1) as error
*/
integer _exit(data_list *ptr)
{
    int i = 0;

    if (ptr->segment[1] != NULL)
    {
        for (; ptr->segment[1][i]; i++)
            if ((ptr->segment[1][i] < '0' || ptr->segment[1][i] > '9') && ptr->segment[1][i] != '+')
            {
                /** The the value is not a num*/
                errno = 2;
                return (2);
            }

        errno = _atoi(ptr->segment[1]);
    }
    /* Else return sucess */
    free_data(ptr);
    exit(errno);
}