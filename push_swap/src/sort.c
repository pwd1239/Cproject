#include "push_swap.h"

int  findTheHighestIndex(t_list *stack)
{
    int index;

    index = stack->index;
    while (stack)
    {
        if (stack->index > index)
            index = stack->index;
        stack = stack->next;
    }
    return (index);
}

void    ft_sortThreeElement(t_list **stack)
{
    int highest;

    if (check_isSorted(*stack))
        return;
    highest = findTheHighestIndex(*stack);
    if ((*stack)->index == highest)
        ft_ra_mouves(stack);
    else if ((*stack)->next->index == highest)
        ft_rra_mouves(stack);
    else if ((*stack)->index > (*stack)->next->index)
        ft_sa(stack);
    
}

void    push_expect_last_three(t_list **stack_a, t_list **stack_b)
{
    int size;
    int element_pushed;
    int i;

    size = ft_lstsize(*stack_a);
    i = 0;
    element_pushed = 0;
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

void ft_shiftStackToLowest(t_list **stack_a)
{
    int lowestPos;
    int size_stack_a;

    size_stack_a = ft_lstsize(*stack_a);
    lowestPos = getTheLOwestPosIndex(stack_a);
    if(lowestPos > size_stack_a / 2)
    {
        while(lowestPos < size_stack_a)
        {
            ft_rra_mouves(stack_a);
            lowestPos++;
        }
    }
    else
    {
        while(lowestPos > 0)
        {
            ft_ra_mouves(stack_a);
            lowestPos--;
        }
    }
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