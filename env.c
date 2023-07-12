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
/**
 * remove_env - This is a function that return the removed env
 * @ptr: This is an argument that reprsent the data list struct
 * @key: This is an argrument that represent the removed env
 * 
 * Return: This function return (1) as rmoved otherwise (0) as not
*/
integer remove_env(string key, data_list *ptr)
{
    integer len = 0, i = 0;

    /* Checking the value arguments passed for error*/
    if (ptr->env == NULL || key == NULL)
        return (0);

    len = _strlen(key);
    while (ptr->env[i])
    {
        if (_strcomp(key, ptr->env[i], len) && ptr->env[i][len] == '=')
        {
            /* If the condition is true free each env placed*/
            free(ptr->env[i]);

            /* moving a step to next position*/
            i++;
            for (; ptr->env[i]; i++)
                ptr->env[i + 1] = ptr->env[i];
            
            /* Place the NULL at the end*/
            ptr->env[i - 1] = NULL;
            return (1);
        }
        i++;
    }
    return (0);
}
/**
 * set_env - This is a function that return the overwrite value of the env
 * @ptr: This is an argument that represent the data list struct
 * @val: This is an argument that reprsent the gven value
 * @key: This is an argument that reprsent the new value
 * 
 * Return: This function return (1) if is NULL (2) as error otherwise
 * (0) as success
*/
integer set_env(string key, string val, data_list *ptr)
{
    integer i = 0, nkey = 1, len = 0;

    /* Checking ecah value*/
    if (ptr->env == NULL || key == NULL || val == NULL)
        return (1);

    /* Get the lenght of the value*/
    len = _strlen(key);

    while (ptr->env[i])
    {
        /* Check if the is any issues*/
        if (_strcomp(key, ptr->env[i], len) && ptr->env[i][len] == '=')
        {
            nkey = 0;
            /* free the variable used */
            free(ptr->env[i]);
            break;
        }
        i++;
    }
    ptr->env[i] = _strcon(_strdup(key), '=');
    ptr->env[i] = _strcon(ptr->env[i], val);

    if (nkey)
    {
        /* If the return a new value the it will create a list an the end */ 
         /* and put a NULL*/
         ptr->env[i + 1] = NULL;
    }
    return (0);
}
