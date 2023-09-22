#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: that is the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_no);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/** file */
void file_open(char *fpath);
int line_parse(char *buff, int line_no, int format);
void r_file(FILE *);
int len_c(FILE *);
void search_func(char *, char *, int, int);
void find_func(char *opcode, char *value, int line_no, int format);
void get_fun(op_func, char *, char *, int, int);

/** string functions */
int _strcmp(const char *str1, const char *str2);
int _isdigit(int d);
int _atoi(char *s);

stack_t *create_node(int n);
void _free(void);
void p_stack(stack_t **, unsigned int);
void add_stack(stack_t **, unsigned int);
void add_queue(stack_t **, unsigned int);

void _add(stack_t **stack, unsigned int line_no);
void _sub(stack_t **stack, unsigned int line_no);
void _mul(stack_t **stack, unsigned int line_no);
void _swap(stack_t **stack, unsigned int line_no);

void _pop(stack_t **stack, unsigned int line_no);
void p_top(stack_t **stack, unsigned int line_no);
void nop(stack_t **stack, unsigned int line_no);

/**
 * errors
*/
void err(int error_no, ...);
void op_err(int error_no, ...);

#endif
