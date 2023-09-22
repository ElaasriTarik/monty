#include "monty.h"
stack_t *head = NULL;
/**
 * main - start the program
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
        err(1);
	file_open(argv[1]);
	_free();
	return (0);
}
