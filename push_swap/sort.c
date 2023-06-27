#include "push_swap.h"

void sortThree(t_list **stack)
{
    while(is_sorted(stack) != 1){
        if(((*stack)->index > (*stack)->next->index) 
            && ((*stack)->index) < (*stack)->next->next->index)
            sa(stack);
        else if(((*stack)->index > ((*stack)->next->index))
            && ((*stack)->index) < (*stack)->next->next->index)
            ra(stack);
        else
            rra(stack);

    }
}

void sortFour(t_list **stack_a, t_list **stack_b)
{
    if(ft_is_order(stack_a, 4) == 1)
        return ;
    rotateToMin(stack_a, 4);
    pb(stack_a, stack_b);
    resetIndex(stack_a);
    sortThree(stack_a);
    pa(stack_a, stack_b);
}

void sort(t_list **stack_a, t_list **stack_b)
{
    int size;

    size = lst_size(*stack_a);
    if(size == 3)
        sortThree(stack_a);
    else if(size == 4)
        sortFour(stack_a, stack_b);
    else{
        if(ft_is_order(stack_a, 5) == 1)
            return ;
        rotateToMin(stack_a, 5);
        pb(stack_a, stack_b);
        resetIndex(stack_a);
        sortFour(stack_a, stack_b);
        pa(stack_a, stack_b);
    }
}