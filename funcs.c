#include "monty.h"

/**
 * find_func - find the right function
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *value, int ln, int format)
{
  int i;
  int flag;

	instruction_t func_list[] = 
    {
		{"push", add_stack},
		{"pall", p_stack},
		{"pint", p_top},
		{"pop", _pop},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
        {"sub", _sub},
		{NULL, NULL}
	};

  if (opcode[0] == '#')
    {
      return;
    }

  for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
    {
      if (strcmp(opcode, func_list[i].opcode) == 0)
	{
	  get_fun(func_list[i].f, opcode, value, ln, format);
	  flag = 0;
	}
    }
  if (flag == 1)
    {
      err(3, ln, opcode);
    }
}

/**
 * _sub - subs the top two elements
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_no: Interger representing the line number of of the opcode.
 */
void _sub(stack_t **stack, unsigned int line_no)
{
	int total;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
		op_err(8, line_no, "add");
    }

	(*stack) = (*stack)->next;
	total = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
