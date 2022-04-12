#include "main.h"

/**
 * router - routes data to appropriate function
 * @input: double pointer to char (tokenized user input)
 * @command_path: pointer to char
 *
 * Return: pointer to function
 */
int (*router(char **input, char *command_path))(char*, char**, char**)
{
	struct stat info;

	(void)command_path;

	if (_strcmp(input[0], "env") == 0)
	{
		return (_penv);
	}
	if (stat(input[0], &info) == 0)
	{
		return (run_program);
	}
	if (_strcmp(input[0], command_path) == 0)
	{
		return (bad_command);
	}
	else
	{
		return (run_program);
	}
}

/* main - test router */

/* Return: always 0 */


/* int main(int argc, char **argv, char **envp) */
/* { */
/*	int (*f)(char *, char **, char **); */

/*	(void)argc; */

/*	argv++; */

/*	f = router(argv, "not used"); */

/*	f("/usr/bin/ls", argv, envp); */

/*	return(0); */
/* } */
