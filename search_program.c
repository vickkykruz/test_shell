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
