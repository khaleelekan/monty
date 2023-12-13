#include "monty.h"

int printShortStackError(unsigned int line_number, char *op);
int printDivError(unsigned int line_number);
int printPopError(unsigned int line_number);
int printPintError(unsigned int line_number);
int printPcharError(unsigned int line_number, char *message);

/**
 * printPopError - Prints pop error messages for empty stacks.
 * @line_number: Line number in script where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int printPopError(unsigned int line_number)
{
    fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
    return EXIT_FAILURE;
}

/**
 * printPintError - Prints pint error messages for empty stacks.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int printPintError(unsigned int line_number)
{
    fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
    return EXIT_FAILURE;
}

/**
 * printShortStackError - Prints monty math function error messages
 *                        for stacks/queues smaller than two nodes.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int printShortStackError(unsigned int line_number, char *op)
{
    fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
    return EXIT_FAILURE;
}

/**
 * printDivError - Prints division error messages for division by 0.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int printDivError(unsigned int line_number)
{
    fprintf(stderr, "L%u: division by zero\n", line_number);
    return EXIT_FAILURE;
}

/**
 * printPcharError - Prints pchar error messages for empty stacks
 *                   and non-character values.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @message: The corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int printPcharError(unsigned int line_number, char *message)
{
    fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
    return EXIT_FAILURE;
}

