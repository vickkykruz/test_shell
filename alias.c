#include "shell.h"
/**
 * buff_add - This is a function that append stings of charcter to the end
 * of the buffer
 * @str: This is an argument that represent the string to be occupied
 * @buff: This is an argument that represent the memory to the stream
 * 
 * Return: This function return the number of space allocate otherwisw error
*/
integer buff_add(string buff, string str)
{
    integer i = 0, len;

    /* Get the initail space that was installed */
    len = _strlen(buff);
    while (str[i])
    {
        /*From the len we add at initize at the same time*/
        buff[len + 1] = str[i];
        i++;
    }
    /* At The end we include the '\0' */
    buff[len + 1] = '\0';
    return(len + 1);
}
/**
 * access_alias - This is a function that return the new allocated alias
 * @ptr: This is an argument that represent the data_list struct
 * @str: This is an argument that represent the string of the alias
 * 
 * Return: This function return the allocated alias
*/
string access_alias(data_list *ptr, string str)
{
    integer len, i = 0;

    /* Validating the arguments passed */
    if (str == NULL || ptr->list == NULL)
        return (NULL);

    len = _strlen(str);

    while (ptr->list[i])
    {
        /* Check for concidence of the string and the environment */
        if (_strcomp(str, ptr->list[i], len) && ptr->list[i][len] == '=')
        {
            /* This will return the value of the string */
            return (ptr->list[i] + len + 1);
        }
    }
    /* Otherwise it will return NULL*/
    return (NULL);
}
/**
 * inest_alias - This is a function that replace an alias in the stream
 * @str: This is an argument that represent the string to be inserted
 * @ptr: This is an argument that represent the data_list struct
 * 
 * Return: The function return a new allocated alias
*/
integer insert_alias(string str, data_list *ptr)
{
    char buff[250];
    string tmp = NULL;
    integer i = 0, k = 0;

    /* Validating all the arguments pased */
    if (ptr->list == NULL || str == NULL)
        return (1);
    
    for (; str[i]; i++)
        if (str[i] != '=')
            buff[i] = str[i];
        else
        {
            /* We search for the value of the alias*/
            tmp = access_alias(ptr, str + i + 1);
            break;
        }
    
    /* Loop throught the string */
    for (; ptr->list[k]; k++)
        if (_strcomp(buff, ptr->list[k], i) && ptr->list[k][i] == '=')
        {
            /* If data is store*/
            free(ptr->list[k]);
            break;
        }
    
    if (tmp)
    {
        buff_add(buff, "=");
        buff_add(buff, tmp);
        ptr->list[k] = _strdup(buff);
    }
    else
        ptr->list[k] = _strdup(str);
    
    return (0);
}
/**
 * alias_expansion - This is a function that return the expaned alias
 * @ptr: This is an argument that represent the data_list struct
 * 
 * Return: This function is a void an it return nothing
*/
void alias_expansion(data_list *ptr)
{
    integer i = 0, count = 0, num = 0;
    char exp[BUFF_SIZE] = {'\0'}, size[BUFF_SIZE] = {0};
    string tmp;

    if (ptr->arg_line == NULL)
        return;

    buff_add(size, ptr->arg_line);

    for (; size[i]; i++)
    {
        while (size[i + count] && size[i + count] != ' ')
        {
            exp[count] = size[i + count];
            count++;   
        }
        exp[count] = '\0';

        tmp = access_alias(ptr, exp);
        if (tmp != NULL)
        {
            exp[0] = '\n';
            buff_add(exp, size + 1 + count); /*Add more space to store char include '\0'*/
            size[i] = '\0';
            buff_add(size, tmp);
            size[_strlen(size)] = '\0';
            buff_add(size, exp);
            num = 1;
        }
        break;
    }
    if (num)
    {
        free(ptr->arg_line);
        ptr->arg_line = _strdup(size);
    }
}
