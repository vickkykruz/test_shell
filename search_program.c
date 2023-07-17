#include "shell.h"
/**
 * validate_file - This is a function that return the validate file status
 * @path: This is an argument that reprsent the give path
 *
 * Return: This function return the status (126) or (0) as sucess otherwise
 * as error
 */
integer validate_file(string path)
{
	struct stat check; /* using the inbuilt struct */

	/* check if it is available */
	if (stat(path, &check) != -1)
	{
		if (S_ISDIR(check.st_mode) || access(path, X_OK))
		{
			/* Give the return status */
			errno = 126;
			return (126);
		}
		/* inan alternative way we return sucess */
		return (0);
	}
	/** Give the status identicating the file doesn't exist */
	errno = 127;
	return (127);
}
/**
 * segment_path - This is a function that return the result of the search path
 * @ptr: This is an argument that reprsent the data list struct
 *
 * Return: This function return the pathnin char *
 */
string *segment_path(data_list *ptr)
{
	integer i = 0, cout_dir = 2;
	string *segment = NULL;
	string PATH;

	/* Access the path value */
	PATH = access_env_key("PATH", ptr);
	if ((PATH == NULL) || PATH[0] == '\0')
		return (NULL); /* this path not found */
	/** Else **/
	PATH = _strdup(PATH);

	/* Get the number of directory */
	while (PATH[i])
	{
		if (PATH[i] == ':')
			cout_dir++;
		i++;
	}

	segment = malloc(sizeof(string) * cout_dir);
	if (segment == NULL)
		return (NULL);

	i = 0;
	segment[i] = _strdup(_strtoken(PATH, ":"));

	while (segment[i++])
	{
		segment[i] = _strdup(_strtoken(NULL, ":"));
	}

	free(PATH);
	PATH = NULL;
	return (segment);
}
/**
 * search_program - This is a function that return the path of the program if
 * found
 * @ptr: This is an argument that reprsent the data list struct
 *
 * Return: This function return (0) as sucess otherwise error
 */
integer search_program(data_list *ptr)
{
	integer i = 0, statusCode = 0;
	string *dir;

	/** Check there is an available command */
	if (!ptr->cmd)
		return (2);

	/* If the value is a full path or an executable in the same path */
	if (ptr->cmd[0] == '/' || ptr->cmd[0] == '.')
		return (validate_file(ptr->cmd));

	free(ptr->segment[0]);
	ptr->segment[0] = _strcon(_strdup("/"), ptr->cmd);
	if (!ptr->segment[0])
		return (2);

	/* Get the directory path */
	dir = segment_path(ptr);
	/* Vaildate value */
	if (!dir || !dir[0])
	{
		errno = 127;
		return (127);
	}

	while (dir[i])
	{
		/** We append the name of the function to the path **/
		dir[i] = _strcon(dir[i], ptr->segment[0]);
		statusCode = validate_file(dir[i]);
		/* if failed or not found we return the err code */
		if (statusCode == 0 || statusCode == 126)
		{
			errno = 0;
			free(ptr->segment[0]);
			ptr->segment[0] = _strdup(dir[i]);
			free_ptr(dir);
			return (statusCode);
		}
		i++;
	}

	free(ptr->segment[0]);
	ptr->segment[0] = NULL;
	free_ptr(dir);
	return (statusCode);
}
