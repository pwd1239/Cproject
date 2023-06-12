#include "push_swap.h"

void swap_stack(t_list *stack)
{
    int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void ft_sa(t_list **stack_a)
{
    swap_stack(*stack_a);
    ft_putstr("sa\n");
}

void ft_sb(t_list **stack_b)
{
    swap_stack(*stack_b);
   ft_putstr("sb\n");
}

void ft_ss(t_list **stack_a, t_list **stack_b)
{
    swap_stack(*stack_a);
    swap_stack(*stack_b);
    ft_putstr("sb\n");
}