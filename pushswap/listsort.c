#include "push_swap.h"


void sortThreeElement(t_list **stack_a)
{
    t_list *a;
    t_list *b;
    t_list *c;

    a = *stack_a;
    b = (*stack_a)->next;
    c = (*stack_a)->next->next;
    while(*stack_a == NULL || (*stack_a)->next == NULL || (*stack_a)->next)
        return;
    while(!(a->data > b->data && b->data < c->data && c->data > a->data))
    {
        if(b->data < a->data && b->data < c->data || (a->data && b->data > c->data && c->data < a->data) || (a->data < b->data && b->data > c->data && c->data))
            ft_sa_mouves(stack_a);
        else if(a->data < b->data && c->data < b->data)
            ft_ra_mouves(stack_a);
        else if(a->data < b->data && b->data > c->data && c->data < a->data)
            ft_rra(stack_a);
        a = *stack_a;
        b = (*stack_a)->next;
        c = (*stack_a)->next->next;
    }
}

void sortFiveElement(t_list **stack_a, t_list **stack_b)
{
    int i;

    i = 2;
    while (i > 0)
    {
        ft_pb_mouves(stack_a, stack_b);
        i++;
    }
    sortThreeElement(stack_a);
    move_from_to_stack_a(stack_a, stack_b);
    min_is_found(stack_a, ft_lstsize(stack_a));
}
