#include "main.h"

/**
 * commander - builds command pathname if it exists
 * @path: pointer to char (PATH string from environment)
 * @input: pointer to char (command name string)
 *
 * Return: pointer to char (full pathname of file)
 *
 * **IMPORTANT NOTE**	Return pointer must be freed
 */
char *commander(char *path, char *input)
{
	char **dir;
	int i;
	char *command, *temp;
	struct stat info;

	if (stat(input, &info) == 0)
	{
		command = malloc(_strlen(input) + 1);
		command = realloc(command, _strlen(input) + 1);
		command = _strcpy(command, input);
		return (command);
	}

	dir = tokenizer(path, ":");

	temp = malloc(_strlen(input) + 2);
	temp = _strcpy(temp, "/");
	temp = _strcat(temp, input);
	temp = _strcat(temp, "\0");

	command = malloc(1);
	for (i = 0; dir[i] != NULL; i++)
	{
		command = realloc(command, _strlen(dir[i]) + _strlen(temp) + 1);
		command = _strcpy(command, dir[i]);
		command = _strcat(command, temp);
		if (stat(command, &info) == 0)
		{
			free(temp);
			temp = NULL;
			tokenizer_free(dir);
			return (command);
		}
	}

	free(temp);
	temp = NULL;
	tokenizer_free(dir);
	command = _strcpy(command, input);
	return (command);
}

   /* int main(int argc, char *argv[], char *envp[]) */
   /* { */
   /* char *path = _getenv("PATH", envp); */

   /* char *command = commander(path, argv[1]); */

   /* (void)argc; */

   /* printf("%s\n", command); */

   /* fflush(NULL); */

   /* free(path); */
   /* free(command); */

   /* return (0); */
   /* } */
