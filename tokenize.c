#include "shell.h"
/**
 * islogic - This is a function that handle the logical operator | and &
 * @arr_cmd: This is an argument that represent the array of command passed
 * @idx: This is an argument that reprsent the  index of the command passed
 * @arr_opt: This is an argument that represent the arr of operation
 * 
 * Return: This function return the idex of the array cmd
*/
integer islogic(string arr_cmd[], integer idx, char arr_opt[])
{
    integer i = 0;
    string tmp = NULL;

    /* Check each character in the command for a | and &  caharcter */
    while (arr_cmd[idx] != NULL && arr_cmd[idx][i])
    {
        /*Check if the char is & and the next is & */
        if (arr_cmd[idx][i] == '&' && arr_cmd[idx][i + 1] == '&')
        {
            /*So if found we spilt it */
            tmp = arr_cmd[idx]; /* Storing that character */
            arr_cmd[idx][i] = '\0'; /* Replace it witha null terminator */
            arr_cmd[idx] = _strdup(arr_cmd[idx]);
            arr_cmd[idx + 1] = _strdup(tmp + i + 2);
            idx++;
            arr_opt[idx] = '&';
            free(tmp);
            i = 0;
        }

        /*Check if the char is | and the next is | */
        if (arr_cmd[idx][i] == '|' && arr_cmd[idx][i + 1] == '|')
        {
            /*So if found we spilt it */
            tmp = arr_cmd[idx]; /* Storing that character */
            arr_cmd[idx][i] = '\0'; /* Replace it witha null terminator */
            arr_cmd[idx] = _strdup(arr_cmd[idx]);
            arr_cmd[idx + 1] = _strdup(tmp + i + 2);
            idx++;
            arr_opt[idx] = '|';
            free(tmp);
            i = 0;
        }
        i++;
    }
   return (idx); 
}
/**
 * _strtoken - This is a function that separtes the strings with delimiters
 * @line: This is an argument that represent the getline source
 * @delim: This is an argument that represnt the limit of the string
 * 
 * Return: This function retutns a new token
*/
string _strtoken(string line, string delim)
{
    string dest;
    int i;
    static string s;

    /* Condition to check if the line contains a NULL */
    if (line != NULL)
        s = line;

    while (*s != '\0')
    {
        i = 0;
        while (delim[i] != '\0')
        {
            if (*s == delim[i])
                break;
            i++;
        }
        if (delim[i] == '\0')
            break;
        s++; /* Looping each character in memory*/
    }
    dest = s;

    /* Condition if the dest was NULL */
    if (*dest == '\0')
        return (NULL);

    while (*s != '\0')
    {
        i = 0;
        while (delim[i] != '\0')
        {
            if (*s == delim[i])
            {
                *s = '\0';
                s++;
                return (dest);
            }
            i++;
        }
        s++;
    }

    return (dest);
}