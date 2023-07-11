#include "shell.h"
/**
 * access_env_key - This is a function that return the value of an env variables
 * @key: This is an argument that represent the env key given
 * @ptr: This is an argument that represent the struct of the data_list
 * 
 * Return: This function return a new allocated pointer
*/
string access_env_key(string key, data_list *ptr)
{
    integer i = 0, len = 0;

    /* Checking the arguments value */
    if (ptr->env == NULL || key == NULL)
        return (NULL);

    /** Get the lenght of the value */
    len = _strlen(key);

    while (ptr->env[i])
    {
        /* Checking for any concidence*/
        if (_strcomp(key, ptr->env[i], len) && ptr->env[i][len] == '=')
        {
            /** Return the value to the key Name*/
            return (ptr->env[i] + len + 1);
        }
        i++;
    }
    return (NULL);
}