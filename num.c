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
/**
 * _atoi - This is a function that return the converted string to integer
 * @str: This is an argument thatvreprsent the given string to be converted
 *
 * Return: This function return the converted string to integer
 */
integer _atoi(string str)
{
	unsigned int num = 0;
	integer i = 1;

	/** validating the vlaue for '0' to '9' in ASCII */
	while (!('0' <= *str && *str <= '9') && *str != '\0')
	{
		if (*str == '-')
			i *= -1;
		if (*str == '+')
			i *= +1;
		str++;
	}
	
	/** valudate the string for the scond str **/
	while ('0' <= *str && *str <= '9' && *str != '\0')
	{
		num = (num * 10) + (*str - '0');

		str++;
	}

	/** return the converted integer **/
	return (num * i);
}
