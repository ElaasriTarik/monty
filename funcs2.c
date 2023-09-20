#include "monty.h"

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_no: Interger representing the line number of of the opcode.
 */
void _pop(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		op_err(7, line_no);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_no: Interger representing the line number of of the opcode.
 */
void p_top(stack_t **stack, unsigned int line_no)
{
	if (stack == NULL || *stack == NULL)
    {
		op_err(6, line_no);
    }
	printf("%d\n", (*stack)->n);
}

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_no: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_no)
{
	(void)stack;
	(void)line_no;
}

/**
 * swap_nodes - Swaps the top two elements
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_no: Interger representing the line number of of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_no)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
		op_err(8, line_no, "swap");
    }
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
    {
		temp->next->prev = *stack;
    }
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * add_nodes - Adds the top two elements
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_no)
{
	int total;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
		op_err(8, line_no, "add");
    }

	(*stack) = (*stack)->next;
	total = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
