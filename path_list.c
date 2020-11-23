#include "awshell.h"

/**
 * path_list - builds the environment list according to envname
 * @envname: name of the environment
 * Return: pointer to the head list
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
p_list *path_list(void)
{
	char *env_value;
	char **entries;
	int i = 0;
	p_list *head = NULL;

	env_value = get_env(PATH);
	entries = split_str(env_value, ":");
	while (entries[i] != NULL)
	{
		add_list(&head, entries[i]);
		i++;
	}
	free_double(entries);
	return (head);
}
