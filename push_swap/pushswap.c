#include "push_swap.h"

int checkDuplicate(t_list *stack)
{
    int tmp;
    t_list *dup;

    while(stack && stack->next)
    {
        tmp = stack->content;
        dup = stack;
        while(dup->next)
        {
            dup = dup->next;
            if(dup->content == tmp)
                return (-1);
        }
        stack = stack->next;
    }
    return (1);

}

void freeStack(t_list **stack)
{
    if(!stack || !(*stack))
        return ;
    freeStack(&((*stack)->next));
    free(*stack);
    *stack = NULL;
}

int stackInit(int ac, char **av, t_list **stack_a)
{
    int i;
    int j;
    char **split;

    i = 1;
    while(i < ac){
        j = 0;
        split = ft_split(av[i], ' ');
        if(!split)
            return (0);
        while(split[j]){
            if(ft_atob(split[j]) > INT_MAX 
                || ft_atob(split[j]) < INT_MIN)
                return (0);
            lst_addback(stack_a, lst_new(ft_atoi(split[j])));
            j++;
        }
        free_split(split);
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    t_list *stack_a;
    t_list *stack_b;

    if(ac == 1)
        return (ft_putstr("Error\n", STDERR_FILENO));
    stack_a = NULL;
    stack_b = NULL;
    if(stackInit(ac, av, &stack_a) == 0)
        return (ft_putstr("Error\n", STDERR_FILENO));
    else if(checkDuplicate(stack_a) == -1)
        return (ft_putstr("Error\n", STDERR_FILENO));
    else{
        AssignIndex(&stack_a);
        if(is_sorted(&stack_a) != 1){
            if(lst_size(stack_a) <= 5)
                sort(&stack_a, &stack_b);
            else
                radix_sort(&stack_a, &stack_b);
        }
    }
    freeStack(&stack_a);
    freeStack(&stack_b);
    return (0);
}