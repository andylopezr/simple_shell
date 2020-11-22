#include "awshell.h"
/**
 * get_builtins - checks if the input command is a builtin
 * @string: name of the environment var to get
 * Return: pointer to the function or NULL if it fails
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
int get_builtins(char *buff, char **buff_split, char *buff_w)
{
	int (*f)();
	unsigned int i, x;
	builtins_t commands[] = {
		{"exit", exitshell},
		{"env", _env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"help", _help},
		{NULL, NULL}
	};

	for (i = 0; commands[i].name; i++)
	{
		x = _strcmp(buff, commands[i].name);
		if (x == 0)
		{
			f = commands[i].function;
			if (i == 0)
				f(buff_split, buff, buff_w);
			f(buff_split);
			return (0);
		}
	}
	return (-1);
}
