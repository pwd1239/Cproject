#include "push_swap.h"

void rotate(t_list **stack)
{
    t_list *tmp;
    t_list *bottom;

    tmp = *stack;
    *stack = (*stack)->next;
    bottom = getTheBottom(*stack);
    tmp->next = NULL;
    bottom->next = tmp;
}

void ft_ra_mouves(t_list **stack_a)
{
    rotate(stack_a);
    write(1, "ra\n", 3);
}

void ft_rb_mouves(t_list **stack_b)
{
    rotate(stack_b);
    write(1, "rb\n", 4);
}

void ft_rr_mouves(t_list **stack_a, t_list **stack_b)
{
    ft_ra_mouves(stack_a);
    ft_rb_mouves(stack_b);
    write(1, "rr\n", 4);
}

void ft_rra_mouves(t_list **stack_a)
{
    t_list *tmp_rra;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    tmp_rra = *stack_a;
    while (tmp_rra->next != NULL)
    {
        tmp_rra = tmp_rra->next;
    }
    // move the last node to top
    tmp_rra->next = *stack_a;
    *stack_a = tmp_rra;
    // update the new last  node
    tmp_rra->next = NULL;
    write(1, "rra\n", 5);
}

void ft_rrb_mouves(t_list **stack_b)
{
    t_list *tmp_rrb;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    tmp_rrb = *stack_b;
    while (tmp_rrb->next != NULL)
    {
        tmp_rrb = tmp_rrb->next;
    }
    // move the last node to top
    tmp_rrb->next = *stack_b;
    *stack_b = tmp_rrb;
    // update the new last  node
    tmp_rrb->next = NULL;
    write(1, "rrb\n", 5);
}

void ft_rrr_mouves(t_list **stack_a, t_list **stack_b)
{
    ft_rra_mouves(stack_a);
    ft_rrb_mouves(stack_b);
    write(1, "rrr\n", 5);
}
