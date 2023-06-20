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
    ft_putchar("ra\n");
}

void ft_rb_mouves(t_list **stack_b)
{
    rotate(stack_b);
    ft_putchar("rb\n");
}

void ft_rr_mouves(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_putchar("rr\n");
}

void	rev_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;
	t_list	*before_tail;

	tail = getTheBottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void ft_rra_mouves(t_list **stack_a)
{
    rev_rotate(stack_a);
    ft_putchar("rra\n");
}

void ft_rrb_mouves(t_list **stack_b)
{
    rev_rotate(stack_b);
    ft_putchar("rrb\n");
}

void ft_rrr_mouves(t_list **stack_a, t_list **stack_b)
{
    rev_rotate(stack_a);
    rev_rotate(stack_b);
    ft_putchar("rrr\n");
}
