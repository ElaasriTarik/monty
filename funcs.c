#include "monty.h"

/**
 * find_func - find the right function
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @line_no: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *value, int line_no, int format)
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
		{"swap", _swap},
		{"add", _add},
        {"sub", _sub},
        {"mul", _mul},
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
	  get_fun(func_list[i].f, opcode, value, line_no, format);
	  flag = 0;
	}
    }
  if (flag == 1)
    {
      err(3, line_no, opcode);
    }
}

/**
 * _sub - subs the top two elements
 * @stack: top node of the stack.
 * @line_no: Interger representing the line number of of the opcode.
 */
void _sub(stack_t **stack, unsigned int line_no)
{
	int total;
	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
    {
		/**op_err(8, line_no, "sub");*/
			fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
            exit(EXIT_FAILURE);
    }

	*stack = (*stack)->next;
	total = (*stack)->n - (*stack)->prev->n;

	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _mul - multiplies the top two elements
 * @stack: top node of the stack.
 * @line_no: Interger representing the line number of of the opcode.
 */
void _mul(stack_t **stack, unsigned int line_no)
{
	int total;
	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
    {
		/**op_err(8, line_no, "mul");*/
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_no);
        exit(EXIT_FAILURE);
    }

	*stack = (*stack)->next;
	total = (*stack)->n * (*stack)->prev->n;

	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
