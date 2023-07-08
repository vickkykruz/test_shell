#include "shell.h"
/**
 * printerr_ch - This is a function that display an array of chars in stderr
 * to the command line
 * @str: This is an argument that represent the given sting passed
 * 
 * Return: This function return the total number of bytes in the string
*/
integer printerr_ch(string str)
{
    integer num, len;

    len = _strlen(str); /*Get the total len of the string*/
    num = write(STDERR_FILENO, str, len );

    return (num);
}
/**
 * print - This is a function that print the chars in stdout in the command line
 * @str: This is an arguent that represent the string pased
 * 
 * Return: This function return the total number of chars passed otherwise -1 (error)
*/
integer print(string str)
{
    integer num, len;

    len = _strlen(str);
    num = write(STDOUT_FILENO, str, len);

    return (num);
}
/**
 * print_err - This is a function that display the char in stderr in the command line
 * @statusCode: This is an argument that represent the error statuscode passed
 * @prt: This is an argument that represnt the struct of the data_list of the data stored
 * 
 * Return: This function return the total number of chars passed otherwise -1 (error) 
*/
integer print_err(integer statusCode, data_list *ptr)
{
    char arr[10] = {'\0'};
    printstr((long) ptr->count, arr, 10);

    switch (statusCode)
    {
    case 127:
        printerr_ch(ptr->arg);
        printerr_ch(": ");
        printerr_ch(arr);
        printerr_ch(": ");
        printerr_ch(ptr->cmd);
        printerr_ch(": not found\n");
        break;
    case 126:
        printerr_ch(ptr->arg);
        printerr_ch(": ");
        printerr_ch(arr);
        printerr_ch(": ");
        printerr_ch(ptr->cmd);
        printerr_ch(": Permission denied\n");
        break;
    case 2 || 3:
        printerr_ch(ptr->arg);
        printerr_ch(": ");
        printerr_ch(arr);
        printerr_ch(": ");
        printerr_ch(ptr->segment[0]);
        if (statusCode != 2)
            printerr_ch(": can't cd to");
        else
            printerr_ch(": Illegal number: ");
        printerr_ch(ptr->segment[1]);
        printerr_ch("\n");
        break;
    default:
        printerr_ch(": program Error\n");
        break;
    }
}
