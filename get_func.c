#include "monty.h"

/**
 * get_fun - Calls the required function.
 * @func: Pointer to the function about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @state: state specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void get_fun(op_func func, char *op, char *val, int ln, int state)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (_strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
        {
			err(5, ln);
        }
		for (i = 0; val[i] != '\0'; i++)
		{
			if (_isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(_atoi(val) * flag);
		if (state == 0)
        {
			func(&node, ln);
        }
		if (state == 1)
        {
			add_queue(&node, ln);
	    }
    }
	else
		func(&head, ln);
}
