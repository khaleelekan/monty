#include "monty.h"

/**
 * f_pstr - Prints the string starting at the top of the stack, followed by a newline.
 * @head: Stack head
 * @counter: Line number
 */
void f_pstr(stack_t **head, unsigned int counter)
{
    stack_t *h;
    (void)counter;

    h = *head;
    while (h && h->n > 0 && h->n <= 127)
    {
        printf("%c", h->n);
        h = h->next;
    }
    printf("\n");
}

