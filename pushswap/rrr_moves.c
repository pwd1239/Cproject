#include "push_swap.h"

void ft_rra_mouves(t_list **stack_a)
{
    t_list *tmp_rra;

    if(*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    tmp_rra = *stack_a;
    while(tmp_rra->next != NULL){
        tmp_rra = tmp_rra->next;
    }
    //move the last node to top
    tmp_rra->next = *stack_a;
    *stack_a = tmp_rra;
    //update the new last  node
    tmp_rra->next = NULL;
}

void ft_rrb_mouves(t_list **stack_b)
{
    t_list *tmp_rrb;

    if(*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    tmp_rrb = *stack_b;
    while(tmp_rrb->next != NULL){
        tmp_rrb = tmp_rrb->next;
    }
    //move the last node to top
    tmp_rrb->next = *stack_b;
    *stack_b = tmp_rrb;
    //update the new last  node
    tmp_rrb->next = NULL;
}

void ft_rrr_mouves(t_list **stack_a, t_list **stack_b){
    ft_rra_mouves(stack_a);
    ft_rrb_mouves(stack_b);
}