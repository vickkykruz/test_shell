#include "shell.h"
/**
 * var_expansion - This is a function that return the expaned variables
 * @ptr: This is an argument that reprsent a pointer that point to the data_list
 * struct
 * 
 * Return: This function returns a void (nothing)
*/
void var_expansion(data_list *ptr)
{
    char exp[BUFF_SIZE] = {'\0'}, size[BUFF_SIZE] = {0};
    string tmp;
    integer i, k;

    if (ptr->arg_line == NULL)
        return;

    buff_add(size, ptr->arg_line);
    for (i = 0; size[i]; i++)
        if (size[i] == '#')
            size[i--] = '\0';
        else if (size[i] == '$' && size[i + 1] == '?')
        {
            size[i] = '\0';
            convertstr(errno, exp, 10);
            buff_add(size, exp);
            buff_add(size, ptr->arg_line + i + 2);
        }
        else if (size[i] == '$' && size[i + 1] == '$')
        {
            size[i] = '\0';
            convertstr(getpid(), exp, 10);
            buff_add(size, exp);
            buff_add(size, ptr->arg_line + i + 2);
        }
        else if (size[i] == '$' && (size[i + 1] == ' ' || size[i + 1] == '\0'))
            continue;
        else if (size[i] == '$')
        {
            for (k = 1; size[i + k] && size[i + k] != ' '; k++)
                exp[k - 1] = size[ i + k];

            tmp = access_env_key(exp, ptr);
            size[i] = '\0', exp[0] = '\0';
            buff_add(exp, size + i + k);
            tmp ? buff_add(size, tmp) : 1;
            buff_add(size, exp);
        }
    if (!_strcomp(ptr->arg_line, size, 0))
    {
        free(ptr->arg_line);
        ptr->arg_line = _strdup(size);
    }
}