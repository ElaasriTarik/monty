#include "monty.h"
stack_t *head = NULL;
/**
 * main - Start of program
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_open(argv[1]);
	_free();
	return (0);
}
