#include "push_swap.h"

void	swap(t_list **stack)
{
	int	index;
	int	content;

	if (!(*stack)->next)
		return ;
	content = (*stack)->next->content;
	index = (*stack)->next->index;
	(*stack)->next->content = (*stack)->content;
	(*stack)->next->index = (*stack)->index;
	(*stack)->content = content;
	(*stack)->index = index;
}

void	sa(t_list **stack)
{
	swap(stack);
	write(1, "sa\n",4);
}

void	sb(t_list **stack)
{
	swap(stack);
	write(1, "sb\n",4);
}

void	ss(t_list **a_stack, t_list **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	write(1, "ss\n",4);
}
