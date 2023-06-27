#include "push_swap.h"

t_list	*lst_last(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void  reverse(t_list **stack)
{
    t_list *lst;

    if(!(*stack) || !(*stack)->next)
        return;
    lst = lst_last(*stack);
    lst->prev->next = NULL;
    lst->prev = NULL;
    lst->next = *stack;
    (*stack)->prev = lst;
    *stack = (*stack)->prev;
}

void rra(t_list **stack){
    reverse(stack);
    write(1, "rra\n", 4);
}

void rrb(t_list **stack){
    reverse(stack);
    write(1, "rrb\n", 4);
}

void rrr(t_list **stack_a, t_list **stack_b){
    reverse(stack_a);
    reverse(stack_b);
    write(1, "rrr\n", 4);
}