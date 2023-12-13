#include "monty.h"
#include <string.h>

/* Function prototypes */
void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);

/* Global variable for opcode tokens */
char **op_toks = NULL;

/**
 * free_tokens - Frees the global op_toks array of strings.
 */
void free_tokens(void)
{
    size_t i = 0;

    if (op_toks == NULL)
        return;

    for (i = 0; op_toks[i]; i++)
        free(op_toks[i]);

    free(op_toks);
}

/**
 * token_arr_len - Gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int token_arr_len(void)
{
    unsigned int toks_len = 0;

    while (op_toks[toks_len])
        toks_len++;
    return (toks_len);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
    int i, j;

    for (i = 0; line[i]; i++)
    {
        for (j = 0; delims[j]; j++)
        {
            if (line[i] == delims[j])
                break;
        }
        if (delims[j] == '\0')
            return (0);
    }

    return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
    instruction_t op_funcs[] = {
        {"push", monty_push},
        {"pall", monty_pall},
        {"pint", monty_pint},
        {"pop", monty_pop},
        {"swap", monty_swap},
        {"add", monty_add},
        {"nop", monty_nop},
        {"sub", monty_sub},
        {"div", monty_div},
        {"mul", monty_mul},
        {"mod", monty_mod},
        {"pchar", monty_pchar},
        {"pstr", monty_pstr},
        {"rotl", monty_rotl},
        {"rotr", monty_rotr},
        {"stack", monty_stack},
        {"queue", monty_queue},
        {NULL, NULL}
    };
    int i;

    for (i = 0; op_funcs[i].opcode; i++)
    {
        if (strcmp(opcode, op_funcs[i].opcode) == 0)
            return (op_funcs[i].f);
    }

    return (NULL);
}

/**
 * run_monty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int run_monty(FILE *script_fd)
{
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0, exit_status = EXIT_SUCCESS;
    unsigned int line_number = 0, prev_tok_len = 0;
    void (*op_func)(stack_t**, unsigned int);

    /* Initialize the stack */
    if (init_stack(&stack) == EXIT_FAILURE)
        return EXIT_FAILURE;

    /* Read and process each line of the Monty script */
    while (getline(&line, &len, script_fd) != -1)
    {
        line_number++;
        op_toks = strtow(line, DELIMS);

        /* Handle empty lines and comments */
        if (op_toks == NULL)
        {
            if (is_empty_line(line, DELIMS))
                continue;
            free_stack(&stack);
            return malloc_error();
        }
        else if (op_toks[0][0] == '#') /* comment line */
        {
            free_tokens();
            continue;
        }

        /* Get the function corresponding to the opcode */
        op_func = get_op_func(op_toks[0]);
        if (op_func == NULL)
        {
            free_stack(&stack);
            exit_status = unknown_op_error(op_toks[0], line_number);
            free_tokens();
            break;
        }

        /* Store the length of op_toks before executing the opcode */
        prev_tok_len = token_arr_len();

        /* Execute the opcode function */
        op_func(&stack, line_number);

        /* Check if the token array length has changed */
        if (token_arr_len() != prev_tok_len)
        {
            /* Update the exit status */
            if (op_toks && op_toks[prev_tok_len])
                exit_status = atoi(op_toks[prev_tok_len]);
            else
                exit_status = EXIT_FAILURE;
            free_tokens();
            break;
        }

        /* Free the tokens after processing a line */
        free_tokens();
    }

    /* Free the stack after script execution */
    free_stack(&stack);

    /* Check for empty line error after reading the script */
    if (line && *line == 0)
    {
        free(line);
        return malloc_error();
    }

    /* Free the line buffer */
    free(line);

    /* Return the exit status of the Monty interpreter */
    return exit_status;
}

