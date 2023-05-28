#include "push_swap.h"

void ft_sa_mouves(t_list **stack_a)
{
    t_list *tmp_a;
    
    if(*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    tmp_a = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp_a = (*stack_a)->next;
    (*stack_a)->next = tmp_a;
}

void ft_sb_mouves(t_list **stack_b){
    t_list *tmp_b;
    
    if(*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    tmp_b = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp_b = (*stack_b)->next;+
    (*stack_b)->next = tmp_b;
}

void ft_ss_mouves(t_list **stack_a, t_list **stack_b)
{
    ft_sa_mouves(stack_a);
    ft_sb_mouves(stack_b);
}

void ft_pa_mouves(t_list **stack_a, t_list **stack_b){
    t_list *ptr1;

    if(*stack_b == NULL)
        return;
--    ptr1 = *stack_b;
    *stack_b = (*stack_b)->next;
    ptr1->next = *stack_a;
    *stack_a = ptr1;
    return;
}

void ft_pb_mouves(t_list **stack_a, t_list **stack_b)
{
    t_list *ptr2;

    if(*stack_a == NULL)
        return;
    ptr1 = *stack_a;
    *stack_a = (*stack_a)->next;
    ptr1->next = *stack_b;
    *stack_b = ptr1;
    return;
}