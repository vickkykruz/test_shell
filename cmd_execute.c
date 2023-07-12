#include "shell.h"
/**
 * execute - This is a function that return the executed command with it path variables allocated
 * @ptr: This is an argument that represent the data_list struct
 * 
 * Return: This function return (0) as success otherwise (-1) as failed
*/
integer execute(data_list *ptr)
{
    pid_t ppt;
    integer status, rev = 0;

    /* Vaidating the program in bulid-in function */
    rev = get_bulllet(ptr);
    if (rev != 1)/* validate the result*/
        return (rev);

    /* Validating the program in program file system*/
    rev = search_program(ptr);
    if (rev)/* if teh program is not found */
        return (rev);
    else
    {
        /*if the program was found, we create a process in the code*/
        ppt = fork(); /* we create a chile process to run before the parent*/
        if (ppt == -1) /* If the child process failed and doesn't return*/
        {/*Dispaly an error and exit the program */
            perror(ptr->cmd);
            exit(EXIT_FAILURE);
        }
        if (ppt == 0)
        {/*If the child process returned */
            rev = execve(ptr->segment[0], ptr->segment, ptr->env); /* Execue the program*/
            if (rev == -1)/*If there was an error in executing the program*/
                perror(ptr->cmd), exit(EXIT_FAILURE);
        }
        else
        {/* Run the wait process before executeing*/
            wait(&status);
            if (WIFEXITED(status))
                errno = WEXITSTATUS(status);
            else if (WIFSIGNALED(status))
                errno = 128 + WTERMSIG(status);
        }
    }
    return (0);
}