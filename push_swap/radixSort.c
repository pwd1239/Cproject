#include "push_swap.h"

int getMaxBits_lst(t_list **stack)
{
    t_list	*lst;
	int		max;
	int		max_b;

	lst = *stack;
	max = lst->index;
	max_b = 0;
	while (lst)
	{
		if (lst->index > max)
			max = lst->index;
		lst = lst->next;
	}
	while ((max >> max_b) != 0)
		max_b++;
	return (max_b);

}

int	lst_size(t_list *stack)
{
	int		i;
	t_list	*lst;

	lst = stack;
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void radix_sort(t_list **stack_a, t_list **stack_b)
{
    t_list	*lst;
	int		i;
	int		j;
	int		size;
	int		max_b;

	lst = *stack_a;
	size = lst_size(*stack_a);
	max_b = getMaxBits_lst(stack_a);
	i = -1;
	while (++i < max_b)
	{
		j = -1;
		while (++j < size)
		{
			lst = *stack_a;
			if (((lst->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		while (lst_size(*stack_b) != 0)
		    pa(stack_a, stack_b);
	}

}