#include "monty.h"

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
    stack_t *current = *stack, *next;

    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *stack = NULL;  // Reset the original pointer after freeing the list
}

/**
 * init_stack - Initializes a stack_t stack with beginning
 *              stack and ending queue nodes.
 * @stack: A pointer to an uninitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
    stack_t *new_stack = malloc(sizeof(stack_t));
    if (new_stack == NULL)
        return malloc_error();

    new_stack->n = STACK;
    new_stack->prev = NULL;
    new_stack->next = NULL;

    *stack = new_stack;

    return EXIT_SUCCESS;
}

/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue) of a stack_t list.
 *
 * Return: If the stack_t is in stack mode - STACK.
 *         If the stack_t is in queue mode - QUEUE.
 *         Otherwise - INVALID_MODE.
 */
int check_mode(stack_t *stack)
{
    if (stack->n == STACK)
        return STACK;
    else if (stack->n == QUEUE)
        return QUEUE;
    else
        return INVALID_MODE;  // Use a named constant or enumeration for clarity
}

