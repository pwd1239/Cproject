#include "push_swap.h"

int check_isSorted(t_list *stack)
{
    while(stack->next != NULL)
    {
        if(stack->data > stack->next->data)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void ft_sortThreeElement(t_list **stack_a){
    int highest;

    if(check_isSorted(stack_a))
        return;
    highest = findTheHighestIndex(stack_a);
    if((*stack_a)->index == highest)
        ft_ra_mouves(stack_a);
    else if((*stack_a)->next->index == highest)
        ft_rra_mouves(stack_a);
    else if((*stack_a)->index > (*stack_a)->next->index)
        ft_sa_moves(stack_a);
    
}

void push_expect_last_three(t_list **stack_a, t_list **stack_b){
    int size;
    int element_pushed;
    int i;

    i = 0;
    element_pushed = 0;
    size = ft_lstsize(*stack_a);
    while(size > 3 && i < size && element_pushed < size / 2){
        if((*stack_a)->index <= size / 2)
        {
            ft_pb_move(stack_a, stack_b);//push the top
            element_pushed++;
        }
        else
            ft_ra_mouves(stack_a);//move the top to bottom
        i++;
    }
    while(size - element_pushed > 3){
        ft_pb_move(stack_a, stack_b);
        element_pushed++;
    }
}

void get_position(t_list **stack)
{
    int i;
    t_list *tmp;

    tmp = *stack;
    while(tmp)
    {
        tmp->pos = i;
        tmp = tmp->next;
        i++;
    }
}

void get_target(t_list **stack_a, int index_b, int target_index, int target_pos)
{
    t_list *tmp_a;

    tmp_a = stack_a;
    while(tmp_a){
        if(tmp_a->index > index_b && tmp_a->index < target_pos)
        {
            target_index = tmp_a->index;
            target_pos = tmp_a->pos;
        }
        tmp_a = tmp_a->next;
    }
    if(target_index != INT_MAX)
        return (target_pos);
    while(tmp_a){
        if(tmp_a->index < target_index){
            target_index = tmp_a->index;
            target_pos = tmp_a->pos;
        }
        tmp_a = tmp_a->next;
    }
    return (target_pos);
}
int  targetPositionFound(t_list **stack_a, t_list **stack_b){
    t_list *tmp;
    int target_pos;

    tmp = *stack_b;
    get_position(stack_a);
    get_position(stack_b);
    while(tmp){
        target_pos = get_target(stack_a, tmp->index, INT_MAX, target_pos);
        tmp->target_pos = target_pos;
        tmp = tmp->next;
    }
}

void ft_shiftStackToLowest(t_list **stack_a){
    int lowestPos;
    int size_stack_a;

    size_stack_a = ft_lstsize(stack_a);
    lowestPos = getTheLOwestPosIndex(stack_a);
    if(lowestPos > size_stack_a / 2){
        while(lowestPos < size_stack_a)
        {
            ft_rra_mouves(stack_a);
            lowestPos++;
        }
    }
    else{
        while(lowestPos > 0){
            ft_ra_mouves(stack_a);
            lowestPos--;
        }
    }
}

void getTheLOwestPosIndex(t_list **stack){
    t_list *tmp;
    int lowestIndex;
    int lowestPos;

    tmp = *stack;
    lowestIndex = tmp->index;
    lowestPos = tmp->pos;
    while(tmp){
        if(tmp->index < lowestIndex){
            lowestIndex = tmp->index;
            lowestPos = tmp->pos;
        }
        tmp =tmp->next;
    }
    return (lowestPos);
}

void ft_sortMoreThanThree(t_list **stack_a, t_list **stack_b)
{
    puch_exepct_last_three(stack_a, stack_b);
    ft_sortThreeElement(stack_a);
    while(*stack_b){
        targetPositionFound(stack_a, stack_b);
        calculate_cost_value(stack_a, stack_b);
        calc_comb_to_find_cheapestMove(stack_a, stack_b);
    }
    if(!check_isSorted(stack_a))
        ft_shiftStackToLowest(stack_a);
}
void swap(t_list **stack_a, t_list **stack_b, int stack_size){
    if(stack_size == 2 && !check_isSorted(stack_a))
        ft_sa_moves(stack_a);
    else if(stack_size == 3)
        ft_sortThreeElement(stack_a);
    else if(stack_size > 3 && !check_isSorted(stack_a))
        ft_sortMoreThanThree(stack_a, stack_b);
}
int main(int ac, char **av)
{
    t_list *stack_a;
    t_list *stack_b;
    int stack_size;

    if(ac < 2)
        return 0;
    if(!ft_isCorrectInput(av))
        exit_error(NULL, NULL);
    stack_a = fill_stack_a(ac, av);
    stack_size = ft_lstsize(stack_a);
    assign_index(stack_a, stack_b);
    swap(stack_a, stack_a, stack_size);
    free(stack_a);
    free(stack_b);
}