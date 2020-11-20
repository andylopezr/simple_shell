#include "awshell.h"

/**
 * get_env - get the environment
 * @str: string where the enviroment is
 * Return: Result
 *                     _
 *     /\             | |
 *    /  \   _ __   __| |_   _
 *   / /\ \ | '_ \ / _` | | | |
 *  / ____ \| | | | (_| | |_| |
 * /_/    \_\_|_|_|\__, |\__, | _   _
 * \ \        / (_)   | | __/ || \ | |
 *  \ \  /\  / / _ ___| ||___/ |  \| |
 *   \ \/  \/ / | / __| __/ _ \| . ` |
 *    \  /\  /  | \__ \ || (_) | |\  |
 *     \/  \/   |_|___/\__\___/|_| \_| |- Nov 2020 -|
 *
 */
char *get_env(char *str)
{
	int i = 0, j = 0;
	char *envcopy, *envcopy2 = NULL;
	char **temp = NULL, *res = NULL;
	(void)str;

	while (environ[i] != NULL)
	{
		envcopy = _strdup(environ[i]);
		envcopy2 = _strdup(environ[i]);
		temp = split_str(envcopy, "=");
		if (strcmp(temp[0], str) == 0)
		{
			res = _strchr(envcopy2, '=');
		}
		while (temp[j] != NULL)
		{
			free(temp[j]);
			j++;
		}
		free(temp);
		free(envcopy);
		free(envcopy2);
		j = 0;
		i++;
	}
	return (res);
}
