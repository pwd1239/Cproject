#include "push_swap.h"

void ft_addFront(t_list **stack, t_list *new)
{
    if(!stack && !new)
        return;
    if(!*stack){
        *stack = new;
        (*stack)->prev = NULL;
        (*stack)->next =NULL;
        return ;
    }
    (*stack)->prev = new;
    new->next = *stack; //linking the new element to the current first element 
    *stack = new;
    new->prev = NULL;
}

void	lst_addback(t_list **stack, t_list *news)
{
	t_list	*tmp;

	if (!stack || !news)
		return ;
	if (!(*stack))
	{
		*stack = news;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = news;
	news->prev = tmp;
}

t_list	*lst_new(int content)
{
	t_list	*stack;

	stack = malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	stack->content = content;
	stack->index = -1;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}
