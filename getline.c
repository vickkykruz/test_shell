#include "shell.h"
/**
 * _getline - This is a custome function that read the command from the prompt
 * @ptr: This is an argument that represent the struct list of the user data stored
 * 
 * Return: This function that return the total bytes
*/
integer _getline(data_list *ptr)
{
    ssize_t i = 0, bytes;
    static char arr_opt[10] = {'\0'};
    static string arr_cmd[10] = {NULL};
    char buffer[BUFF_SIZE] = {'\0'};
    integer len;

    /* Handle the '|' and & operator if it doesn't exist in the cmd */
    if (!arr_cmd[0] || (arr_opt[0] == '&' && errno != 0) || (arr_opt[0] == '|' && errno == 0))
    {
        /* If any any memory was allocated we want to free it*/
        i = 0;

        while (arr_cmd[i])
        {
            free(arr_cmd[i]);
            arr_cmd[i] = NULL; /* Redeclare it as NULL*/
            i++;
        }

        /* We want to read the command from the propmt to the memory buffer */
        bytes = read(ptr->desc, &buffer, BUFF_SIZE);
        if (bytes <= 0)/* If it failed */
            return (-1);

        /* token each line including \n */
        i = 0;
        do
        {
            arr_cmd[i] = _strdup(_strtoken(i ? NULL : buffer, "\n;"));
            /*Checking for || and && in the command */
            i = islogic(arr_cmd, i, arr_opt);
        } while (arr_cmd[i++]);
    }

    ptr->arg_line = arr_cmd[0];
    i = 0;
    while (arr_cmd[i])
    {
        arr_cmd[i] = arr_cmd[i + 1];
        arr_opt[i] = arr_opt[i + 1];
    }

    len = _strlen(ptr->arg_line);

    return (len);
}
