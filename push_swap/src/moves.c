#include "push_swap.h"

void rotate_both1(t_list **stack_a, t_list **stack_b, int *numOfRot_a, int *numOfRot_b)
{
    while(*numOfRot_a < 0 && *numOfRot_b < 0)
    {
        (*numOfRot_a)++;
        (*numOfRot_b)++;
        ft_rrr_mouves(stack_a, stack_b);
    }
}

void rotate_both2(t_list **stack_a, t_list **stack_b, int *numOfRot_a, int *numOfRot_b)
{
    while(*numOfRot_a > 0 && *numOfRot_b > 0)
    {
        (*numOfRot_a)--;
        (*numOfRot_b)--;
        ft_rr_mouves(stack_a, stack_b);
    }
}

void rotate_stack_a(t_list **stack_a, int *numOfRotation)
{
    while(*numOfRotation)
    {
        if(*numOfRotation > 0)
        {
            ft_ra_mouves(stack_a);
            (*numOfRotation)--;
        }
        else if(*numOfRotation < 0)
        {
            ft_rra_mouves(stack_a);
            (*numOfRotation)++;
        }
    }
}

void rotate_stack_b(t_list **stack_b, int *numOfRotation)
{
    while(*numOfRotation)
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


void move(t_list **stack_a, t_list **stack_b, int numOfRot_a, int numOfRot_b)
{
    if(numOfRot_a < 0 && numOfRot_b < 0)
        rotate_both1(stack_a, stack_b, &numOfRot_a, &numOfRot_b);
    else if(numOfRot_a > 0 && numOfRot_b > 0)
        rotate_both2(stack_a, stack_b, &numOfRot_a, &numOfRot_b);
    rotate_stack_a(stack_a, &numOfRot_a);
    rotate_stack_b(stack_b, &numOfRot_b);
    ft_pa_mouve(stack_a, stack_b);
}