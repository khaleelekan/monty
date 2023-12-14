#include "monty.h"

/**
 * f_pchar - Prints the char at the top of the stack, followed by a new line.
 * @head: Stack head
 * @counter: Line number
 */
void f_pchar(stack_t **head, unsigned int counter)
{
    stack_t *top;

    top = *head;
    if (!top)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    if (top->n > 127 || top->n < 0)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", top->n);
}

