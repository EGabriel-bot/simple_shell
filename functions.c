#include "main.h"

/**
 * bad_command - handles commands not in the path or special to JABS shell
 * @command_path: pointer to char
 * @input: double pointer to user input
 * @envp: double pointer to environment
 *
 * Return: always 0
 */
int bad_command(char *command_path, char **input, char **envp)
{
	(void)command_path;
	(void)envp;

	write(1, input[0], _strlen(input[0]));
	write(1, ": command not found\n", 20);

	return (0);
}


/**
 * _penv - print environment
 * @envp: double pointer to environment variable
 *
 * Return: always 0
 */

int _penv(char **envp)
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		write(1, envp[i], _strlen(envp[i]));
		write(1, "\n", 2);
	}

	return (0);
}
