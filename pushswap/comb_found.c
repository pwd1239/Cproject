#include "push_swap.h"

int specific_set_value(t_list *stack_a, int *arr, int max){
    int i;
    int pos;

    i = 0;
    pos = 0;
    while(stack_a != NULL){
        i = 0;
        while(stack_a->content != arr[i] && i < max){
            if(i == max - 1)//elements of arr have been found in the stack
                return(pos);
            i++;
        }
        stack_a = stack_a->next;
        pos++;
    }
    return(-1);// Not all elements of arr were found in the stack
}

int max_found(int *arr_a, int *arr_b){
    int i;

    i = 0;
    if(arr_a[i] > arr_b[i])
        return (arr_a[i]);
    else
        return (arr_b[i]);
}

int ft_combination(int *arr_a, int *arr_b, int *tmp, int size)
{
    int i;
    int pos;

    i = 0;
    pos = 0;
    //ensures that the loop iterates from i = 1 to i = size - 1
    while(++i < size)
    {
        if(tmp[i] < tmp[pos])
            pos = i;
    }
    free(arr_a);
    free(arr_b);
    free(tmp);
    return (pos);
}

int calcule_combination(int *arr_a, int *arr_b, int size)
{
    int i;
    int *tmp;

    i = 0;
    tmp = (int *)malloc(sizeof(int) * size);
    if(!arr_a || !arr_b)
        display_error();
    while(i++ < size){
        if((arr_a[i] > 0 && arr_b > 0) || (arr_a[i] < 0 && arr_b[i] < 0))
            max_found(arr_a[i], arr_b[i]);
        else
            if(arr_a[i] < 0 > 0 && b > 0)
                arr_a[i] *= -1;
            if(arr_b[i] < 0)
                arr_b[i] *= -1;
            tmp[i] = arr_a[i] + arr_b[i];
    }
    return(ft_combination(arr_a, arr_b, tmp, size));
}

int move_from_to_stack_a(int a, int b, t_list *stack_a, t_list *stack_b)
{
    int b_value;

    b_value = b;
    while(a < 0 && b < 0){
        ft_rrr_mouves(stack_a, stack_b);
        a++;
        b++;
    }
    while(a > 0 || b > 0)
    {
        ft_rr_mouves(stack_a, stack_b);
        a--;
        b--;
    }
    while(a < 0){
        ft_rra_mouves(stack_a);
        a++;
    }
    if(a > 0){
        while(a-- > 0)
             ft_ra_mouves(stack_a);
    }
    return (b_value);
}

int move_from_to_stack_b(t_list **stack_a, t_list **stack_b, int *arr, int size){
    int i;
    int size_a;

    size_a = ft_lstsize(stack_a);
    i = calcule_combination(stack_a, arr, size_a);
    while(i != -1)
    {
        if(i > 0)
        {
            while(i-- > 0)
                ft_ra_mouves(stack_a);
        }
        ft_pb_mouves(stack_a, stack_b);
        i = calcule_combination(stack_a, arr, size_a);
    }
}
void min_is_found(t_list **stack_a, int size)
{
    int pos;
    int min;
    int pos_min;
    t_list *tmp;

    tmp = *stack_a;
    pos = 0;
    min = tmp->content;
    while(pos < size){
        if(min > tmp->content){
            min = tmp->content;
            pos_min = pos;
        }
        tmp = tmp->next;
        pos++;
    }
    tmp = NULL;
    pos = ft_max_value_b(pos_min, size);
    move_from_to_stack_a(pos, 0, stack_a, &tmp);
}

int ft_max_or_min(t_list *stack_a, int cont, int size)
{
    t_list *tmp;
    int i;
    int max;
    int min;

    i = 0;
    tmp = stack_a;
    max = stack_a->content;
    min = stack_a->content;
    while( tmp != NULL){
        if(tmp ->content == cont)//element found at position i
            return (i);
        else if(tmp->content > max)
            max = tmp->content;
        else if(tmp->content < min)
            min = tmp->content;
        tmp = tmp->next;
        i++;
    }
    if(cont == max)
        return (size);//indicate it is the max value
        //size indicate the total number of element i the stack
    else if(cont == min)
        return (size - 1);
    else
        return (-1);
    
    
}
/*determine the needed value for an element in the stack help to determine 
the optimal operation or moves required to sort the stack in the desire order*/
int ft_max_value_a(t_list *stack_a, int content, int size)
{
    t_list *tmp;
    int i;

    i = 1;
    tmp = stack_a;
    //to determine if the max or min value in astack
    i = ft_max_or_min(stack_a, content, size);
    if(i != size + 1)//element found 
        return (ft_max_value_b(i, size));
    while(tmp != NULL)
        tmp = tmp->next;
    //control the first and the last element to check if content is aoutside the range  
    while((content < stack_a->content) && (content > tmp->content))
        return (0);
    while(!(content > stack_a->content) && (content < (stack_a->next)->content)){
        stack_a = stack_a->next;
        i++; //keep track the number of iterations
    }
    return (ft_max_value_b(i, size));

}
int ft_max_value_b(int max, int size)
{
    if (max > (size / 2))
        max -= size;
    return (max);
}

int bestnumber_com(t_list **stack_b, int size_b, t_list **stack_a, int size_a)
{
    int *arr_a;
    int *arr_b;
    t_list *tmp_b;
    int i;

    tmp_b = *stack_b;
    arr_a = (int *) malloc(sizeof(int) * size_a);
    arr_b = (int *) malloc(sizeof(int) * size_b);
    i = 0;
    while(++i < size_b)
        arr_b[i] = ft_max_value_b(i, size_b);
    while(++i < size_b && tmp_b != NULL){
        arr_a[i] = ft_max_value_a(*stack_a, tmp_b->content, size_a);
        tmp_b = tmp_b->next;
    }
    i = calcule_combination(arr_a, arr_b, size_a);
    i = move_from_to_stack(arr_a[i], arr_b[i], stack_a, stack_b);
    free(arr_a);
    free(arr_b);
    return(i);
}
