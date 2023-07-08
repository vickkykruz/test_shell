#include "shell.h"
/**
 * _strlen - This is a function that return the total len of
 * a string
 * @str: This is an argument that represent the given str
 * 
 * Return: This function return the total lenght of the string
*/
integer _strlen(string str)
{
    integer len = 0;

    /* Check if the argument contains a NULL*/
    if (str == NULL)
        return (0);

    while (str[len] != '\0')
        len++;

    return (--len);
}
/**
 * str_rev - This is a function that return the reversed string
 * @str: This is an argument that represent the given string passed
 * 
 * Return: This function return a void
*/
void str_rev(string str)
{
    char s;
    integer len, i = 0;

    len = _strlen(str) - 1;
    while (i < len)
    {
        /* Swap each chars*/
        s = str[i];
        str[i++] = str[len];
        str[len--] = s;
    }
}
/**
 * convertstr - This is a function that return the converted number to string
 * @num: This is an argument that reprsent the number needed to be converted
 * @str: This is an argument that represent the number of string to be stored
 * @b: This is an argument that represent the base to be converted
 * 
 * Return: This function is a void and it return nothing
*/
void convertstr(long_number num, string str, integer b)
{
    integer idx, nive = 0;
    char arr[] = HEX;
    long_number con = num;

    if (con == 0)
        str[idx++] = '0';

    if (str[0] == '-')
        nive++;

    while (con)
    {
        str[idx++] = (con < 0) ? arr[-(con % b)] : arr[con % b];
        con /= b;
    }
    if (nive)
        str[idx++] = '-';

    str[idx] = '\0';
    str_rev(str);
}
/**
 * _strdup - This is a function that return the duplicate string passed
 * @str: This is an argument that represent the give string passed
 * 
 * Return: This function return the duplicated sting as pointer
*/
string _strdup(string str)
{
    integer len, i = 0;
    string dest;

    if (str == NULL)
        return (NULL);

    /* Get the lenght of the string */
    len = _strlen(str);
    len = len + 1; /* Adding The '\0' */

    dest = malloc(sizeof(str) * len);
    if (dest == NULL)
    {
        /* Display and error */
        perror("Error");
        errno = ENOMEM; /* Error: Not enought space */
        return (NULL);
    }

    while (i < len)
    {
        dest[i] = str[i];
        i++;
    }

    return (dest);
    
}