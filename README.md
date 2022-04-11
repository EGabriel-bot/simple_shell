# simple_shell
## Simple Shell Project

## Description
This project is a simple version of the Unix shell command interpeter.

## What is the shell?
Shell is a UNIX term for the interactive user interface with an operating system. The shell is the layer of programming that understands and executes the commands a user enters. In some systems, the shell is called a command interpreter.

*Example of the use of the shell:*
![image](https://user-images.githubusercontent.com/72264752/162797818-60d5518e-90ca-49ee-b91b-7b8bc90e44a9.png)

## Prototype
`int main(__attribute__((unused))int argc,__attribute__((unused)) char *argv[], char *envp[])`

- ARGC and ARGV are unused arguments.

- Envp is an inherited environment variable.

- Return 0 if succesful and ERROR if command is not found.

## Compile
Every file that composed the whole project is compiled using the following flags:

`gcc -Wall -Werror -Wextra - pedantic`

## Testing

We have tested our simple shell extensively and it has some bugs.

## Bugs


## Output
*Example of our custom shell*

## About
This simple shell project is part of the first trimester for the Holberton School foundations course.
