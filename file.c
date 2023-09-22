#include "monty.h"

/**
 * file_open - opens a file
 * @fpath: the file namepath
 * Return: void
 */

void file_open(char *fpath)
{
	FILE *f_descr = fopen(fpath, "r");

	if (f_descr == NULL || fpath == NULL)
    {
		err(2, fpath);
    }
	r_file(f_descr);
	fclose(f_descr);
}


/**
 * r_file - reads a file
 * @f_descr: pointer to file descriptor
 * Return: void
 */

void r_file(FILE *f_descr)
{
	int line_no, state = 0;
	char *buff = NULL;
	size_t len = 0;

	for (line_no = 1; getline(&buff, &len, f_descr) != -1; line_no++)
		state = line_parse(buff, line_no, state);
	free(buff);
}

/**
 * line_parse - Separates each line into tokens to determine
 * which function to call
 * @buff: line from the file
 * @line_no: line number
 * @state:  storage state. If 0 Nodes will be entered as a stack.
 */

int line_parse(char *buff, int line_no, int state)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buff == NULL)
    {
		/**err(4);*/
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
	opcode = strtok(buff, delim);
	if (opcode == NULL)
    {
		return (state);
    }
	value = strtok(NULL, delim);

	if (_strcmp(opcode, "stack") == 0)
    {
		return (0);
    }
	if (_strcmp(opcode, "queue") == 0)
    {
		return (1);
    }

	find_func(opcode, value, line_no, state);
	return (state);
}
