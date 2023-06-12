#include "push_swap.h"

void swaping(t_list **stack_a, t_list **stack_b, int stack_size)
{
    if(stack_size == 2 && !check_isSorted(*stack_a))
        ft_sa(stack_a);
    else if(stack_size == 3)
        ft_sortThreeElement(stack_a);
    else if(stack_size > 3 && !check_isSorted(*stack_a))
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
    stack_b = NULL;
    stack_a = fill_stack_a(ac, av);
    stack_size = ft_lstsize(stack_a);
    assign_index(stack_a, stack_size + 1);
    swaping(&stack_a, &stack_b, stack_size);
    freeStack(stack_a);
    freeStack(stack_b);
    return (0);
}