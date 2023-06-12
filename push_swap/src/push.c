#include "push_swap.h"

void ft_pa_mouve(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp_ptr;

    if(*stack_a == NULL)
        return;
    tmp_ptr = *stack_b;
    tmp_ptr->next = *stack_a;
    *stack_a = tmp_ptr;
    ft_putchar("pa\n");
}

void ft_pb_move(t_list **stack_a, t_list **stack_b){
    t_list  *tmp_ptr;

    if(*stack_a == NULL)
        return;
    tmp_ptr = *stack_a;
    tmp_ptr->next = *stack_b;
    *stack_b = tmp_ptr;
    ft_putchar("pb\n");
}