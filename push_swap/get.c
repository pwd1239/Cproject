#include "push_swap.h"

t_list *getTheMin(t_list **stack)
{
    t_list *lst;
    t_list *lstMin;
    int min;

    min = 0;
    lstMin = NULL;
    lst = *stack;
    if(!(*stack))
        return (NULL);
    while(lst){
        if((lst->index == -1) 
            && (!min || lst->content < lstMin->content)){
                lstMin = lst;
                min = 1;
            }
            lst = lst->next;
    }
    return (lstMin);
}

void  AssignIndex(t_list **stack){
    t_list *lst;
    int index;

    index = 0;
    lst = getTheMin(stack);
    while(lst){
        lst->index = index;
        lst = getTheMin(stack);
        index++;
    }
}