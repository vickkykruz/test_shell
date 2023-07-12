#include "shell.h"
/**
 * char_count - This is a function that count the string character
 * @str: This is an argument that reprsent the given string
 * @ch: This is an argument that rprsent the given charcter to be count
 * 
 * Return: This function return the strinas int
*/
integer char_count(string str, string ch)
{
    integer count = 0, i;

    for (i = 0; str[i]; i++)
    {
        if (str[i] == ch[0])
            count++;
    }
    return (count);
}