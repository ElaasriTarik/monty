#include "monty.h"

/**
 * err - Prints appropiate error messages
 * @error_no: The error codes are the following: 1, 2, 3, 4, 5.
 */
void err(int error_no, ...)
{
	va_list args;
	char *operation;
	int line_no;

	va_start(args, error_no);
	switch (error_no)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			line_no = va_arg(args, int);
			operation = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_no, operation);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	_free();
	exit(EXIT_FAILURE);
}

/**
 * op_err - handles errors.
 * @error_no: The error codes are the following: 6, 7, 8, 9
 */
void op_err(int error_no, ...)
{
	va_list args;
	char *operation;
	int line_no;

	va_start(args, error_no);
	switch (error_no)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(args, int));
			break;
		case 8:
			line_no = va_arg(args, unsigned int);
			operation = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_no, operation);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	_free();
	exit(EXIT_FAILURE);
}
