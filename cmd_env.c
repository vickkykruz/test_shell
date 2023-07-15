#include "shell.h"
/**
 * _env - This is a function that display the env during runtime
 * @ptr: This is an argument that reprsent the data list struct
 *
 * Return: Thus function return a (0) as sucess otherwise error
 */
integer _env(data_list *ptr)
{
	char buff[50] = {'\0'};
	integer i = 0;
	string tmp = NULL;

	if (ptr->segment[1] == NULL)
		print_env(ptr);
	else
	{
		while (ptr->segment[1][i])
		{
			/* vaildate the char if is = */
			if(ptr->segment[1][i] == '=')
			{
				/*check the if they are of the same name */
				tmp = _strdup(access_env_key(buff, ptr));
				if (tmp != NULL)
					set_env(buff, ptr->segment[1] + 1 + 1, ptr);
				print_env(ptr);
				if (access_env_key(buff, ptr) == NULL)
				{
					/* print the variable */
					print(ptr->segment[1]);
					print("\n");
				}
				else
				{
					/* Return the old value */
					set_env(buff, tmp, ptr);
					free(tmp);
				}
				return (0);
			}
			buff[i] = ptr->segment[1][i];
			i++;
		}
		errno = 2;
		perror(ptr->cmd);
		errno = 127;
	}
	return (0);
}
/**
 * _unsetenv - This is a function that return the unset env process
 * @ptr: This is an argumrnt that reprsent the data list struct
 *
 * Return: This is a functon that return (0) as success otherwise error
 */
integer _unsetenv(data_list *ptr)
{
	/* Checking the value in the argument */
	if (ptr->segment[1] == NULL)
		return (0);

	/* Check the second index */
	if (ptr->segment[2] != NULL)
	{
		perror(ptr->cmd);
		errno = E2BIG;
		return (5);
	}
	remove_env(ptr->segment[1], ptr);
	return (0);
}
/**
 * _setenv - This is a function that return the builtin command set
 * environment
 * @ptr: This is an argument that reprsent the data list struct
 *
 * Return: This function return (0) as sucess otherwise error
 */
integer _setenv(data_list *ptr)
{
	/** Vaildate the value **/
	if (ptr->segment[1] == NULL || ptr->segment[2] == NULL)
		return (0);

	/** if the last segment is null we will return **/
	if (ptr->segment[3] != NULL)
	{
		perror(ptr->cmd);
		errno = E2BIG;
		return (5);
	}
	set_env(ptr->segment[1], ptr->segment[2], ptr);
	return (0);
}
