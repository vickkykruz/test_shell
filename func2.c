#include "shell.h"
/**
 * str_rev - This is a function that return the reversed string
 * @str: This is an argument that represent the given string
 * 
 * Return: This funnction return a void
*/
void str_rev(string str)
{
    char ch;
    integer i, len;

    len = _strlen(str) - 1;
    while ( i < len)
    {
        ch = str[i];
        str[i++] = str[len];
        str[len--] = ch;
    }
}
/**
 * _strcon - This is a function that return the concatenated strings
 * @s1: This is an argument that reprsent the given string 1
 * @s2: This is an argument that reprsent the given string 2
 * 
 * Return: This function return the new contacatenated string
*/
string _strcon(string s1, string s2)
{
    integer len1 = 0, len2 = 0, len = 0;
    string new_str;

    /* Validate the argument value*/
    if (s1 == NULL)
        s1 = "";
    
    if (s2 == NULL)
        s2 = "";

    len1 = _strlen(s1);
    len2 = _strlen(s2);
    len = len1 + len2 + 1;

    /* Allocated memory for the new string*/
    new_str = malloc(sizeof(char) * len);
    if (new_str == NULL)
    {
        perror("Error");
        errno = ENOMEM;
        return (NULL);
    }

    /* Dupliace from s1 to the new string*/
    for (len1 = 0; s1[len1] != '\0'; len1++)
        new_str[len1] = s1[len1];
    free(s1);

    /* Duplicate from s2 to contination of s1*/
    for (len2 = 0; s2[len2] != '\0'; len2++)
    {
        new_str[len1] = s2[len2];
        len1++;
    }
    /* Include the null terminator '\0'*/
    new_str[len1] = '\0';
    return (new_str);
}