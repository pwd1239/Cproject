#include "push_swap.h"

void get_position(t_list **stack)
{
    int i;
    t_list *tmp;

    tmp = *stack;
    i = 0;
    while(tmp)
    {
        tmp->pos = i;
        tmp = tmp->next;
        i++;
    }
}

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

int get_target(t_list **stack_a, int index_b, int target_index, int target_pos)
{
    t_list *tmp_a;

    tmp_a = *stack_a;
    while(tmp_a)
    {
        if(tmp_a->index > index_b && tmp_a->index < target_pos)
        {
            target_index = tmp_a->index;
            target_pos = tmp_a->pos;
        }
        tmp_a = tmp_a->next;
    }
    if(target_index != INT_MAX)
        return (target_pos);
    while(tmp_a)
    {
        if(tmp_a->index < target_index){
            target_index = tmp_a->index;
            target_pos = tmp_a->pos;
        }
        tmp_a = tmp_a->next;
    }
    return (target_pos);
}

void  targetPositionFound(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;
    int target_pos;

    tmp = *stack_b;
    get_position(stack_a);
    get_position(stack_b);
    target_pos = 0;
    while(tmp)
    {
        target_pos = get_target(stack_a, tmp->index, INT_MAX, target_pos);
        tmp->target_pos = target_pos;
        tmp = tmp->next;
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

int getTheLOwestPosIndex(t_list **stack)
{
    t_list *tmp;
    int lowestIndex;
    int lowestPos;

    tmp = *stack;
    lowestIndex = INT_MAX;
    get_position(stack);
    while(tmp)
    {
        if(tmp->index < lowestIndex)
        {
            lowestIndex = tmp->index;
            lowestPos = tmp->pos;
        }
        tmp =tmp->next;
    }
    return (lowestPos);
}
