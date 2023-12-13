#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - Entry point for the Monty interpreter.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int main(int argc, char **argv) {
    FILE *script_fd = NULL;
    int exit_code = EXIT_SUCCESS;

    /* Check if the correct number of arguments is provided */
    if (argc != 2)
        return usage_error();

    /* Open the Monty script file */
    script_fd = fopen(argv[1], "r");
    if (script_fd == NULL)
        return f_open_error(argv[1]);

    /* Run the Monty interpreter with the provided script file */
    exit_code = run_monty(script_fd);

    /* Close the script file */
    fclose(script_fd);

    /* Return the exit code of the Monty interpreter */
    return exit_code;
}

