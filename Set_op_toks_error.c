#include "monty.h"

/**
 * set_op_tok_error - Sets the last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_tok_error(int error_code)
{
    int toks_len = 0;
    char *exit_str = NULL;
    char **new_toks = NULL;

    /* Get the current length of op_toks array */
    toks_len = token_arr_len();

    /* Allocate memory for a new op_toks array with one additional element */
    new_toks = malloc(sizeof(char *) * (toks_len + 2));
    if (!new_toks)
    {
        /* Handle memory allocation error */
        malloc_error();
        return;
    }

    /* Copy existing tokens to the new array */
    for (int i = 0; i < toks_len; i++)
        new_toks[i] = op_toks[i];

    /* Convert the error code to a string */
    exit_str = get_int(error_code);
    if (!exit_str)
    {
        /* Handle memory allocation error */
        free(new_toks);
        malloc_error();
        return;
    }

    /* Add the error code string to the new array and set the last element to NULL */
    new_toks[toks_len++] = exit_str;
    new_toks[toks_len] = NULL;

    /* Free the existing op_toks array and update it to the new one */
    free(op_toks);
    op_toks = new_toks;
}

