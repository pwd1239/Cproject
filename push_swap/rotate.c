#include "push_swap.h"

void rotate(t_list **stack)
{
    t_list *last;

    if(!(*stack) || !(*stack)->next)
        return;
    last = lst_last(*stack);
    last->next = *stack;//the next pointer of the last element (lst) point to the first element (*stack),
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last->next->prev = last;
    last->next->next = NULL;
}

void ra(t_list **stack)
{
    rotate(stack);
    write(1, "ra\n", 3);
}

void rb(t_list **stack)
{
    rotate(stack);
    write(1, "rb\n", 3);
}

void rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1, "rr\n", 3);
}