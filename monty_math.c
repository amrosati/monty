#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: head of stack
 * @line_number: line number in bytecode file
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed, so that at the end:
 * - The top element of the stack contains the result
 * - The stack is one element shorter
 *
 * Return: non
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		math_op(stack, 1);
		return;
	}

	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	free_driver();
	exit(EXIT_FAILURE);
}

/**
 * sub - subtracts th top element from the second of the stack
 * @stack: ...
 * @line_number: ...
 *
 * Return: ...
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		math_op(stack, 2);
		return;
	}

	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	free_driver();
	exit(EXIT_FAILURE);
}

/**
 * _div - divides the second top element by the top element of the stack
 * @stack: ...
 * @line_number: ...
 *
 * Return: ...
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		if (!(*stack)->n)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free_driver();
			exit(EXIT_FAILURE);
		}

		math_op(stack, 3);
		return;
	}

	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	free_driver();
	exit(EXIT_FAILURE);
}