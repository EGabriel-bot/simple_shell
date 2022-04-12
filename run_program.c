#include "main.h"

/**
 * run_program - executes a program that exists in PATH
 * @command_path: full pathname of program file
 * @input: double pointer to user input
 * @envp: double pointer to environment
 *
 * Return: integer value
 */
int run_program(char *command_path, char **input, char **envp)
{
	int tmp, status;

	tmp = fork();
	if (tmp == 0)
	{
		execve(command_path, input, envp);
	}
	if (tmp > 0)
	{
		wait(&status);
	}

	return (0);
}

/*
int main(int argc, char **argv, char**envp)
{
	char *command = "/bin/ls";

	(void)argc;

	run_program(command, argv, envp);

	return (0);
}
*/
