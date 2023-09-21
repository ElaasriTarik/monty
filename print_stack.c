#include "monty.h"

/**
 * p_stack - prints the stack
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_no: line number of  the opcode.
 */
void p_stack(stack_t **stack, unsigned int line_no)
{
	stack_t *temp;
    (void) line_no;

	if (stack == NULL)
    {
		exit(EXIT_FAILURE);
    }
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
