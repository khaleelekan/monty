#include "monty.h"

/**
 * monty_push - Pushes a value onto a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_push(stack_t **stack, unsigned int line_number) {
    stack_t *tmp, *new_node;
    int value;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        set_op_tok_error(malloc_error());
        return;
    }

    if (op_toks[1] == NULL) {
        set_op_tok_error(no_int_error(line_number));
        return;
    }

    value = atoi(op_toks[1]);

    if (check_mode(*stack) == STACK) {
        tmp = (*stack)->next;
        new_node->prev = *stack;
        new_node->next = tmp;
        if (tmp)
            tmp->prev = new_node;
        (*stack)->next = new_node;
    } else {
        tmp = *stack;
        while (tmp->next)
            tmp = tmp->next;
        new_node->prev = tmp;
        new_node->next = NULL;
        tmp->next = new_node;
    }
}

/**
 * monty_pall - Prints the values of a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_pall(stack_t **stack, unsigned int line_number) {
    stack_t *tmp = (*stack)->next;

    while (tmp) {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
    (void)line_number;
}

/**
 * monty_pint - Prints the top value of a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int line_number) {
    if ((*stack)->next == NULL) {
        set_op_tok_error(pint_error(line_number));
        return;
    }

    printf("%d\n", (*stack)->next->n);
}

/**
 * monty_pop - Removes the top element of a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_pop(stack_t **stack, unsigned int line_number) {
    stack_t *next = NULL;

    if ((*stack)->next == NULL) {
        set_op_tok_error(pop_error(line_number));
        return;
    }

    next = (*stack)->next->next;
    free((*stack)->next);
    if (next)
        next->prev = *stack;
    (*stack)->next = next;
}

/**
 * monty_swap - Swaps the top two elements of a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_swap(stack_t **stack, unsigned int line_number) {
    stack_t *tmp;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL) {
        set_op_tok_error(short_stack_error(line_number, "swap"));
        return;
    }

    tmp = (*stack)->next->next;
    (*stack)->next->next = tmp->next;
    (*stack)->next->prev = tmp;
    if (tmp->next)
        tmp->next->prev = (*stack)->next;
    tmp->next = (*stack)->next;
    tmp->prev = *stack;
    (*stack)->next = tmp;
}

