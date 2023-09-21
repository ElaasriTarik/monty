#include "monty.h"


/**
 * add_queue - Adds a node to queue.
 * @new_node: Pointer to the new node.
 * @line_no: line number of the opcode.
 */
void add_queue(stack_t **new_node, __attribute__((unused))unsigned int line_no)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;

}

/**
 * add_stack - Adds a node
 * @new_node: Pointer to the new node.
 * @line_no: Interger representing the line number of of the opcode.
 */
void add_stack(stack_t **new_node, __attribute__((unused))unsigned int line_no)
{
	stack_t *temp;
	if (new_node == NULL || *new_node == NULL)
    {
		exit(EXIT_FAILURE);
    }
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}
