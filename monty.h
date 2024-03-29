#ifndef __MONTY_H__
#define __MONTY_H__


/* Include */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>


#define UNUSED(X) ((void) X)


/* Data Structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: previous element
 * @next: next element
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


/* function pointer naming */

typedef void (*opfunc)(stack_t **, unsigned int);


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @operation: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	opfunc operation;
} instruction_t;


/* Global */

/**
 * struct global_var - main variable for interpreting
 * @bc_file: bytecode file pointer
 * @line_number: line number in file
 * @islifo: flag of wether is stack of queue
 * @head: head of data structure(stack or queue)
 * @arg: argument for "push" opcode
 * @line: line string buffer
 *
 * Description: global variable to handle file interpreting
 * for stack, queue, FIFO, LIFO
 */

struct global_var
{
	FILE *bc_file;
	unsigned int line_number;
	int islifo;
	stack_t *head;
	char *arg;
	char *line;
};

extern struct global_var *driver;


/* Functions Prototypes */

/* Error functions */

void push_error(unsigned int);
void math_error(const char *, unsigned int);
void div_error(unsigned int);
void malloc_error(void);


/* Util functions */

FILE *check_usage(FILE **, int, char **);
opfunc get_opfunc(char *);
void driver_init(FILE *);
void free_driver(void);
void math_op(stack_t **, unsigned int);
size_t getsize(size_t *);


/* opcodes functions */

void _push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);


/* math opcodes functions */

void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);


/* stack functions */

stack_t *push(stack_t **, int);
void free_stack(stack_t *);


/* switch functions */

void lifo(stack_t **, unsigned int);
void queue(stack_t **, unsigned int);
stack_t *enqueue(stack_t **, int);


#endif /* __MONTY_H__ */
