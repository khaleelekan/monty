#include "monty.h"

/**
 * monty_nop - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_nop(stack_t **stack, unsigned int line_number) {
    (void)stack;
    (void)line_number;
}

/**
 * monty_pchar - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_pchar(stack_t **stack, unsigned int line_number) {
    if ((*stack)->next == NULL) {
        set_op_tok_error(pchar_error(line_number, "stack empty"));
        return;
    }

    int char_value = (*stack)->next->n;

    if (char_value < 0 || char_value > 127) {
        set_op_tok_error(pchar_error(line_number, "value out of range"));
        return;
    }

    printf("%c\n", char_value);
}

/**
 * monty_pstr - Prints the string contained in a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_pstr(stack_t **stack, unsigned int line_number) {
    stack_t *tmp = (*stack)->next;

    while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127)) {
        printf("%c", tmp->n);
        tmp = tmp->next;
    }

    printf("\n");

    (void)line_number;
}

