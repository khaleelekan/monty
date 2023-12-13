#include "monty.h"

/**
 * monty_add - Adds the top two values of a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_add(stack_t **stack, unsigned int line_number) {
    if ((*stack)->next == NULL || (*stack)->next->next == NULL) {
        set_op_tok_error(short_stack_error(line_number, "add"));
        return;
    }

    (*stack)->next->next->n += (*stack)->next->n;
    monty_pop(stack, line_number);
}

/**
 * monty_sub - Subtracts the second value from the top of a stack_t linked list
 *             by the top value.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_sub(stack_t **stack, unsigned int line_number) {
    if ((*stack)->next == NULL || (*stack)->next->next == NULL) {
        set_op_tok_error(short_stack_error(line_number, "sub"));
        return;
    }

    (*stack)->next->next->n -= (*stack)->next->n;
    monty_pop(stack, line_number);
}

/**
 * monty_div - Divides the second value from the top of a stack_t linked list
 *             by the top value.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_div(stack_t **stack, unsigned int line_number) {
    if ((*stack)->next == NULL || (*stack)->next->next == NULL) {
        set_op_tok_error(short_stack_error(line_number, "div"));
        return;
    }

    if ((*stack)->next->n == 0) {
        set_op_tok_error(div_error(line_number));
        return;
    }

    (*stack)->next->next->n /= (*stack)->next->n;
    monty_pop(stack, line_number);
}

/**
 * monty_mul - Multiplies the second value from the top of a stack_t linked list
 *             by the top value.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_mul(stack_t **stack, unsigned int line_number) {
    if ((*stack)->next == NULL || (*stack)->next->next == NULL) {
        set_op_tok_error(short_stack_error(line_number, "mul"));
        return;
    }

    (*stack)->next->next->n *= (*stack)->next->n;
    monty_pop(stack, line_number);
}

/**
 * monty_mod - Computes the modulus of the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_mod(stack_t **stack, unsigned int line_number) {
    if ((*stack)->next == NULL || (*stack)->next->next == NULL) {
        set_op_tok_error(short_stack_error(line_number, "mod"));
        return;
    }

    if ((*stack)->next->n == 0) {
        set_op_tok_error(div_error(line_number));
        return;
    }

    (*stack)->next->next->n %= (*stack)->next->n;
    monty_pop(stack, line_number);
}

