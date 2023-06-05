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
    if(*stack_a->index == highest)
        ft_ra_mouves(stack_a);
    else if(*stack_a->next->index == highest)
        ft_rra_mouves(stack_a);
    else if(*stack_a->index > *stack_a->next->index)
        ft_sa_moves(stack_a);
    
}

void ft_sortMoreThanThree(t_list **stack_a)
void swap(t_list **stack_a, t_list **stack_b, int stack_size){
    if(stack_size == 2 && !check_isSorted(stack_a))
        ft_sa_moves(stack_a);
    else if(stack_size == 3)
        ft_sortThreeElement(stack_a);
    else if(stack_size > 3 && !check_isSorted(stack_a))
        ft_sortMoreThanThree(stack_a);
}
int main(int ac, char **av){
    t_list *stack_a;
    t_list *stack_b;

    while()
}
