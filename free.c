#include "shell.h"
/**
 * free_ptr - This is an function that free each pointer allocated
 * @ptr: This is an argument that represent the point to the address
 * of the memory allocated
 * 
 * Return: This function is avoid and it return nothing
*/
void free_ptr(string *ptr)
{
    integer i = 0;
     if (ptr ==  NULL)
        return;
    
    while (ptr[i])
    {
        free(ptr[i]);
        i++;
    }
    free(ptr);
    ptr = NULL;
}
/**
 * free_repetitive_data - This is a function that free each space allocated in
 * the memory
 * @ptr: This is an argument that represent the data_list struct
 * 
 * Return: This function return a void that is noting
*/
void free_repetitive_data(data_list *ptr)
{
    /* Free each field in the data_list struct */
    if (ptr->segment)
        free_ptr(ptr->segment);

    if (ptr->arg_line)
        free(ptr->arg_line);

    if (ptr->cmd)
        free(ptr->cmd);

    /** Set the feild to NULL **/
    ptr->cmd = NULL;
    ptr->segment = NULL;
    ptr->arg_line = NULL;
}
/**
 * free_data - This is a function that free the data allocated in the memory
 * @ptr: This is an argument thatrespresent the data_list struct the hold the
 * unused data
 * 
 * Return: This function is a void and it return nothing
*/
void free_data(data_list *ptr)
{
    /** If there is no file desctortion stored **/
    if (ptr->desc != 0)
    {
        if (close(ptr->desc))
            perror(ptr->arg);
    }
    free_repetitive_data(ptr);
    free_ptr(ptr->list);
    free_ptr(ptr->env);
}
