#include "shell.h"
/**
 * shell_loop - This is a function that loop the program after an exection
 * has been made.
 * @prompt: This is an argument that showcase the prompot to the user
 * @prt: This is an argument that reprsent the struct the data_list use to store
 * the data or responsd passed
 * 
 * Return: This function return a void (nothing)
*/
void shell_loop(string prompt, data_list *ptr)
{
    integer len, statusCode = 0;

    /* Create the loop that does the following operation */
    while (++(ptr->count))
    {
        /* Display the prompt to the user*/
        print(prompt);

        /* Get the command inputed by the user*/
        len = _getline(ptr);
        statusCode = len; /* Initizaled the vale of len to statusCode*/

        /* Handle the Ctrl command */
        if (statusCode == EOF)
        {
            /*If there an memory allocation in the heap, we free it*/
            free_data(ptr);
            exit(errno);/*Break the loop with an errno status*/
        }

        /*If the len doesn't return 0 */
        if (len >= 1)
        {
            var_expansion(ptr);
            alias_expansion(ptr);
            /* Partition the command inputed*/
            partition(ptr);
            if (ptr->segment[0])
            {
                /* Get the statusCode after executing the command*/
                statusCode = execute(ptr);
                /*If the returned status code was successful display error info*/
                if (statusCode > 0)
                    print_err(statusCode, ptr); /*Passing whatever statuCode value and info*/
            }

            /* Free the data allocation in the memory if there is any break/failure*/
            free_repetitive_data(ptr);
        }
    }
}
