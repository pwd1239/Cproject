#include "push_swap.h"


t_list *fill_stack_a(int ac, char **av)
{
    t_list *stack_a;
    int i;
    long  nb;

    stack_a = NULL;
    nb = 0;
    i = 1;
    while(i < ac)
    {
        nb = ft_atoi(av[i]);
        if(nb > INT_MAX || nb < INT_MIN)
            exit_error(&stack_a, NULL);
        else if(i == 1)
            stack_a =  newStack((int)nb);
        else
            ft_lstadd_back(&stack_a, newStack((int)nb));
        i++;
    }
    return (stack_a);
}

//Assigns an index to each value in stack a
void assign_index(t_list *stack_a, int stack_size)
{
    t_list *ptr;
    t_list *highest;
    int data;

    while(--stack_size > 0)
    {
        ptr = stack_a;
        data = INT_MIN;
        highest = NULL;
        while(ptr)
        {
            if(ptr->data == INT_MIN && ptr->index == 0)
                ptr->index = 1;
            else if(ptr->data > data && ptr->index == 0)
            {
                data = ptr->data;
                highest = ptr;
                ptr = stack_a;
            }
            else
                ptr = ptr->next;
        }
        // if a stack element with the highest value is found, its index is properly assigned, 
        //indicating its position in the sorted order.
        if(highest != NULL)
            highest->index = stack_size;
    }
}