#include "push_swap.h"

// function calculates the cost values (cost_a and cost_b) for each element in stack_b based on their positions and target positions in the stacks

void    calculate_cost_value(t_list **stack_a, t_list **stack_b)
{
    t_list  *tmp_b;
    int     size_a;
    int     size_b;

    tmp_b = *stack_b;
    size_a = ft_lstsize(*stack_a);
    size_b = ft_lstsize(*stack_b);
    while(tmp_b != NULL){
        tmp_b->numOfRotation_b = tmp_b->pos;
        if(tmp_b->pos > size_b/2)
            tmp_b->numOfRotation_b = (size_b - tmp_b->pos) * -1;
        tmp_b->numOfRotation_a = tmp_b->target_pos;
        if(tmp_b->numOfRotation_a > size_a/2)
            tmp_b->numOfRotation_a = (size_a - tmp_b->target_pos) * -1;
        tmp_b = tmp_b->next;
    }
    
}

void    calc_comb_to_find_cheapestMove(t_list **stack_a, t_list **stack_b)
{
    t_list  *tmp;
    int     cheapest;
    int     numOfRotation_a;
    int     numOfRotation_b;

    cheapest = INT_MAX;
    tmp = *stack_b;
    while (tmp != NULL)
    {
        if (ft_abs(tmp->numOfRotation_a) + ft_abs(tmp->numOfRotation_b) < ft_abs(cheapest))
        {
            cheapest = ft_abs(tmp->numOfRotation_a) + ft_abs(tmp->numOfRotation_b);
            numOfRotation_a = tmp->numOfRotation_a;
            numOfRotation_b = tmp->numOfRotation_b;
        }
        tmp = tmp->next;

    }
    move(stack_a, stack_b, numOfRotation_a, numOfRotation_b);
}
