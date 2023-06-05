#include "push_swap.h"

void ft_sa_moves(t_list **stack_a)
{
    t_list *tmp_a;
    
    if(*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    tmp_a = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp_a = (*stack_a)->next;
    (*stack_a)->next = tmp_a;
}

void ft_sb_moves(t_list **stack_b){
    t_list *tmp_b;
    
    if(*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    tmp_b = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp_b = (*stack_b)->next;
    (*stack_b)->next = tmp_b;
}

void ft_rrr_mouves(t_list **stack_a, t_list **stack_b)
{
    ft_rra_mouves(stack_a);
    ft_rrb_mouves(stack_b);
}

void ft_rr_mouves(t_list **stack_a, t_list **stack_b)
{
    ft_ra_mouves(stack_a);
    ft_rb_mouves(stack_b);
}

void rotate_both1(t_list **stack_a, t_list **stack_b, int *numOfRot_a, int *numOfRot_b){
    while(numOfRot_a < 0 && numOfRot_b < 0)
    {
        (*numOfRot_a)++;
        (*numOfRot_b)++;
        ft_rrr(stack_a, stack_b);
    }
}

void rotate_both2(t_list **stack_a, t_list **stack_b, int *numOfRot_a, int *numOfRot_b){
    while(numOfRot_a > 0 && numOfRot_b > 0){
        (*numOfRot_a)--;
        (*numOfRot_b)--;
        ft_rr(stack_a, stack_b);
    }
}

void rotate_stack_a(t_list *stack_a, int *numOfRotation)
{
    while(*numOfRotation != NULL)
    {
        if(*numOfRotation > 0)
        {
            ft_ra_mouves(stack_a);
            (*numOfRotation)--;
        }
        else if(*numOfRotation < 0
        ){
            ft_rra_mouves(stack_a);
            (*numOfRotation)++;
        }
    }
}

void rotate_stack_b(t_list *stack_b, int *numOfRotation){
    while(*numOfRotation != NULL)
    {
        if(*numOfRotation > 0)
        {
            ft_rb_mouves(stack_b);
            (*numOfRotation)--;
        }
        else if(*numOfRotation < 0)
        {
            ft_rrb_mouves(stack_b);
            (*numOfRotation)++;
        }
    }
}
void ft_pa_move(t_list **stack_a, t_list **stack_b)
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

void move(t_list **stack_a, t_list **stack_b, int numOfRot_a, int numOfRot_b)
{
    if(numOfRot_a < 0 && numOfRot_b < 0)
        rotate_both1(stack_a, stack_b, numOfRot_a, numOfRot_b);
    else if(numOfRot_a > 0 && numOfRot_b > 0)
        rotate_both2(stack_a, stack_b, numOfRot_a, numOfRot_b);
    rotate_stack_a(stack_a, &numOfRot_a);
    rotate_stack_b(stack_b, &numOfRot_b);
    ft_pa_mouves(stack_a, stack_b);
    
}