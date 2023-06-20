#include "push_swap.h"

t_list *getTheBottom(t_list *stack)
{
    while(stack && stack->next != NULL)
        stack =stack->next;
    return (stack);
}

t_list	*get_stack_before_bottom(t_list *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_list *newStack(int data)
{
    t_list *new;

    new = (t_list *)malloc(sizeof * new);
    if(!new)
        return NULL;
    new->data = data;
    new->index = 0;
    new->pos = -1;
    new->target_pos = -1;
    new->numOfRotation_a = -1;
    new->numOfRotation_b = -1;
    new->next = NULL;
    return (new);
}

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = getTheBottom(*stack);
	tail->next = new;
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
