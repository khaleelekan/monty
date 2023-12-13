#include "monty.h"

int printUsageError(void);
int printMallocError(void);
int printFileOpenError(char *filename);
int printUnknownOpError(char *opcode, unsigned int line_number);
int printNoIntError(unsigned int line_number);

/**
 * printUsageError - Prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int printUsageError(void)
{
    fprintf(stderr, "USAGE: monty file\n");
    return EXIT_FAILURE;
}

/**
 * printMallocError - Prints malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int printMallocError(void)
{
    fprintf(stderr, "Error: malloc failed\n");
    return EXIT_FAILURE;
}

/**
 * printFileOpenError - Prints file opening error messages with the file name.
 * @filename: Name of the file that failed to open.
 *
 * Return: (EXIT_FAILURE) always.
 */
int printFileOpenError(char *filename)
{
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    return EXIT_FAILURE;
}

/**
 * printUnknownOpError - Prints unknown instruction error messages.
 * @opcode: Opcode where the error occurred.
 * @line_number: Line number in Monty bytecodes file where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int printUnknownOpError(char *opcode, unsigned int line_number)
{
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    return EXIT_FAILURE;
}

/**
 * printNoIntError - Prints invalid monty_push argument error messages.
 * @line_number: Line number in Monty bytecodes file where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int printNoIntError(unsigned int line_number)
{
    fprintf(stderr, "L%u: usage: push integer\n", line_number);
    return EXIT_FAILURE;
}

