#include "push_swap.h"

void push(t_list **src, t_list **dst)
{
    t_list *tmp;

    if(!src)
        return;
    tmp = (*src)->next;
    ft_addFront(src, *dst);
    (*dst) = tmp;
}

void pa(t_list **stack_a, t_list **stack_b)
{
    push(stack_a, stack_b);
    write(1, "pa\n", 3);

}

void pb(t_list **stack_a, t_list **stack_b){
    push(stack_a, stack_b);
    write(1, "pb\n", 3);

}