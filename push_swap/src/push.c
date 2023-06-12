#include "push_swap.h"

void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void ft_pa_mouve(t_list **stack_a, t_list **stack_b)
{
    push(stack_a, stack_b);
    write(1, "pa\n", 3);
}

void ft_pb_move(t_list **stack_a, t_list **stack_b)
{
    push(stack_a, stack_b);
    write(1, "pb\n", 3);
}