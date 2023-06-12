#include "push_swap.h"

int check_isSorted(t_list *stack)
{
    while (stack->next != NULL)
    {
        if (stack->data > stack->next->data)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void    push_expect_last_three(t_list **stack_a, t_list **stack_b){
    int size;
    int element_pushed;
    int i;

    i = 0;
    element_pushed = 0;
    size = ft_lstsize(*stack_a);
    while (size > 6 && i < size && element_pushed < size / 2)
    {
        if ((*stack_a)->index <= size / 2)
        {
            ft_pb_move(stack_a, stack_b);//push the top
            element_pushed++;
        }
        else
            ft_ra_mouves(stack_a);//move the top to bottom
        i++;
    }
    while (size - element_pushed > 3)
    {
        ft_pb_move(stack_a, stack_b);
        element_pushed++;
    }
}

void    ft_sortThreeElement(t_list **stack_a)
{
    int highest;

    if (check_isSorted(*stack_a))
        return;
    highest = findTheHighestIndex(*stack_a);
    if ((*stack_a)->index == highest)
        ft_ra_mouves(stack_a);
    else if ((*stack_a)->next->index == highest)
        ft_rra_mouves(stack_a);
    else if ((*stack_a)->index > (*stack_a)->next->index)
        ft_sa(stack_a);
    
}

void ft_sortMoreThanThree(t_list **stack_a, t_list **stack_b)
{
    push_expect_last_three(stack_a, stack_b);
    ft_sortThreeElement(stack_a);
    while(*stack_b)
    {
        targetPositionFound(stack_a, stack_b);
        calculate_cost_value(stack_a, stack_b);
        calc_comb_to_find_cheapestMove(stack_a, stack_b);
    }
    if(!check_isSorted(*stack_a))
        ft_shiftStackToLowest(stack_a);
}