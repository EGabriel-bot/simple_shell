#include "main.h"
#define unused __attribute__((unused))

/**
 * main - simple shell main function
 * @argc: pointer to argument count (currently unused)
 * @argv: pointer to argument vector (currently unused)
 * @envp: double pointer to the environment
 *
 * Return: Return 0 if successful and ERROR if the command does not exists
 */
int main(unused int argc, unused char *argv[], char *envp[])
{
	int (*f)(char *, char **, char **);
	char **input, *lineptr = NULL, *path, *command_path;
	size_t n = 0;
	int i, flag;

/*	signal(SIGINT, (void (*)(int))sig_c_handler);*/
	while (1)
	{
		if(isatty(0))
			write(1, "JABS$ ", 6);
		/*lineptr needs free*/
		if (getline(&lineptr, &n, stdin) == -1)
		{
			free(lineptr);
			lineptr = NULL;
			exit(0);
		}

		flag = 0;
		for (i = 0; lineptr[i] != '\0'; i++)
		{
			if (lineptr[i] == ' ' || lineptr[i] == '\n' || lineptr[i] == '\t')
			{	

			}	
			else
			{
				flag++;
			}
			i++;
		}

		if (flag == 0)
			continue;

		if (lineptr[0] == '\n')
			continue;

		/*path needs free*/
		path = _getenv("PATH", envp);
		/*input needs tokenizer_free*/
		input = tokenizer(lineptr, " \n");

/*		if (input[0] == 0)
		{
			free(path);
			free(input);
			tokenizer_free(input);
			free(lineptr);
			lineptr = NULL;
			continue;
		}
*/
		if (_strcmp(input[0], "exit") == 0)
		{
			free(lineptr);
			lineptr = NULL;
			free(path);
			path = NULL;
			tokenizer_free(input);
			exit(0);
		}
		/*command_path needs free*/
		command_path = commander(path, input[0]);
		f = router(input, command_path);
		f(command_path, input, envp);
		free(lineptr);
		lineptr = NULL;
		free(path);
		path = NULL;
		tokenizer_free(input);
		free(command_path);
		command_path = NULL;
	}
	return (0);
}


/**
 * sig_c_handler - defines action for SIGINT (ctrl c)
 * @signum: int signal number representing ctrl c
 *
 * Return: no return value
 */

/*
int sig_c_handler(int signum)
{
	(void)signum;
	flag = 1;
}
*/
