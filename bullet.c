#include "shell.h"
/**
 * get_bulllet - This is a function that looks for a match and excute the builtin associated with it
 * @ptr: This is an argument that represnt the data_list struct
 * 
 * Return: This function return (0) as match otherwise (-1) as not match
*/
integer get_bulllet(data_list *ptr)
{
    integer i = 0;
    builin_fun call_fun[] = BUITIN_FUNC;

    /*Looping the the strct cmd */
    while (call_fun[i].cmd != NULL)
    {
        /* If there was a match, between thw cmd and bulit-in cmd */
        if (_strcomp(call_fun[i].cmd, ptr->cmd, 0))
        {
            /* return the exected function and the value of the function*/
            return (call_fun[i].fun(ptr));
        }
        i++;
    }
    /** If there was no match */
    return (-1);
}
