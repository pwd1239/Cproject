#include "push_swap.h"

// moving the top element to the bottom of the stack.
void ft_ra_mouves(t_list **stack_a){
    t_list *tmp_ra;
    t_list *last_a;

    if(*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    tmp_ra = *stack_a;
    last_a = *stack_a;
    while(last_a->next != NULL){
        tmp_ra = last_a;
        last_a = last_a->next;
    }
    last_a->next = *stack_a;
    *stack_a = last_a;
    tmp_ra->next = NULL;
}

void ft_rb_mouves(t_list **stack_b){
    t_list *tmp_rb;
    t_list *last_b;

    if(*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    tmp_rb = *stack_b;
    last_b = *stack_b;
    while(last_b->next != NULL){
        tmp_rb = last_b;
        last_b = last_b->next;
    }
    last_b->next = *stack_b;
    *stack_b = last_b;
    tmp_rb->next = NULL;
}

void ft_rr_mouves(t_list **stack_a, t_list **stack_b)
{
    ft_ra_mouves(stack_a);
    ft_rb_mouves(stack_b);
}