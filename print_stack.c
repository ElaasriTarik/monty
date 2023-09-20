#include "monty.h"

/**
 * p_stack - prints the stack
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_no: line number of  the opcode.
 */
void p_stack(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp;
    (void) line_no;

	if (stack == NULL)
    {
		exit(EXIT_FAILURE);
    }
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
