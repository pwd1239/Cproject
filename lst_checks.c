#include "push_swap.h"

void display_error(){
    write(1, "error\n", 6);
    exit(1);
}
//function to check if the element is present in the list
void  lst_check_int(t_list *stack_a, int check)
{
    while (stack_a->next != NULL)
    {
        /* code */
        if(*(int *)stack_a->content == check)
            display_error();
        stack_a = stack_a->next;
    }
    return;
}

//function check if the elements are in ascending order
void isAscending(t_list *stack_a)
{
    if(stack_a == NULL || stack_a->next == NULL)
        return ;
    while(stack_a->next != NULL)
    {
        if (stack_a->content > stack_a->next->content){
            write(1, "The list is not in ascending order\n", 36);
            return;
        }
        stack_a = stack_a->next;
    }
    write(1, "The list is in ascending order\n", 32);
    
}

void isDescending(t_list *stack_a)
{
    if(stack_a == NULL || stack_a->next == NULL)
        return ;
    while(stack_a->next != NULL)
    {
        if (stack_a->content < stack_a->next->content){
            write(1, "The list is not in descending order\n", 36);
            return;
        }
        stack_a = stack_a->next; 
    }
    write(1, "The list is in descending order\n", 33);
}

//creating a linked list based on the command line 
void ft_write_list(t_list **stack_a, int ac, char **av, int i)
{
    t_list *arg;

    arg = NULL;
    while(i < ac)
    {
        arg = ft_lstnew(ft_atoi(av[i]));
        ft_lstadd_back(*stack_a, arg);
        lst_check_int(*stack_a, arg->content);
    }
    isAscending(stack_a);
    isDescending(stack_a);
    arg = NULL;

}

void ft_rrr_action_value(t_list **stack_a, t_list **stack_b, char *str)
{
    if(ft_strcmp(str, "rra\n"))
        ft_rra_mouves(stack_a);
    if(ft_strcmp(str, "rrb\n"))
        ft_rrb_mouves(stack_b);
    if(ft_strcmp(str, "rrr\n"))
        ft_rrr_mouves(stack_a, stack_b);
}
void ft_ss_action_value(t_list **stack_a, t_list **stack_b, char *str)
{
    while(str != NULL)
    {
        if(ft_strcmp(str, "sa\n"))
            ft_sa_mouves(stack_a);
        if(ft_strcmp(str, "sb\n"))
            ft_sb_mouves(stack_b);
        if(ft_strcmp(str, "ss\n"))
            ft_ss_mouves(stack_a, stack_b);
        if(ft_strcmp(str, "ra\n"))
            ft_ra_mouves(stack_a);
        if(ft_strcmp(str, "rb\n"))
            ft_rb_mouves(stack_b);
        if(ft_strcmp(str, "rr\n"))
            ft_rr_mouves(stack_a, stack_b);
        if(ft_strcmp(str, "pa\n"))
            ft_pa_mouves(stack_a, stack_b);
        else
            ft_rrr_action_value(stack_a, stack_b, str);
    }
}

void ft_argument_check(t_list **stack_a, int ac, char **av)
{
    int i;
    char *arg;

    i = ;
    if(ac == 2)
    {
        arg = ft_split(av[1], ' ');
        while(arg[i] != NULL)
            i++;
        ft_write_list(stack_a, i, arg, 0);
        free(arg);
    }
    if(ac >= 3)
        ft_write_list(stack_a, i, arg, 1);
}

int main(int ac, char **av[])
{
    char str; //a character pointer to store input from the user.
    t_list *stack_a;
    t_list *stack_b;
    int i;

    stack_a = NULL;
    stack_b = NULL;
    i = 0;
    if (ac > 2)
        return (0);
    else
        ft_argument_check(&stack_a, ac, av);
    write(1, "Enter your input: ", 19);
    fgets(str, sizeof(str), stdin);
    ft_ss_action_value(&stack_a, &stack_b, str);
    isAscending(stack_a);

}