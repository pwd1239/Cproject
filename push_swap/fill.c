#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int	i;
	int	sign;

	nbr = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	return (nbr * sign);
}

t_list *newStack(int data){
    t_list *new;

    new = (t_list *)malloc(sizeof * new);
    if(!new)
        return NULL;
    new->data = data;
    new->index = 0;
    new->pos = -1;
    new->target_pos = -1;
    new->numOfRotation_a = -1;
    new->numOfRotation_b = -1;
    new->next = NULL;
    return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (!*lst)
	{
		(*lst) = new;
		return ;
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
}

void exit_error(t_list **stack_a, t_list **stack_b)
{
    if(stack_a == NULL && *stack_a != NULL)
        free(stack_a);
    if(stack_b == NULL && *stack_b != NULL)
        free(stack_b);
    write(1, "Error\n", 7);
    exit(EXIT_FAILURE);
}

//fill the values in the stack A
t_list fill_stack_a(int ac, char **av){
    t_list **stack_a;
    int i;
    long int nb;

    while(i < ac){
        nb = ft_atoi(av[i]);
        if(nb > INT_MAX || nb < INT_MIN)
            exit_error(&stack_a, NULL);
        else if(i == 1)
            *stack_a =  newStack((int)nb);
        else
            ft_lstadd_back(stack_a, newStack((int)nb));
        i++;
    }
    return (stack_a);
}

//Assigns an index to each value in stack a
void assign_index(t_list *stack_a, int stack_size){
    t_list *ptr;
    t_list *highest;
    int data;

    while(--stack_size > 0)
    {
        ptr = stack_a;
        data = INT_MIN;
        highest = NULL;
        while(ptr)
        {
            if(ptr->data == INT_MIN && ptr->index == 0)
                ptr->index = 1;
            else if(ptr->data > data && ptr->index == 0)
            {
                data = ptr->data;
                highest = ptr;
                ptr = *stack_a;
            }
            else
                ptr = ptr->next;
        }
        // if a stack element with the highest value is found, its index is properly assigned, 
        //indicating its position in the sorted order.
        if(highest != NULL)
            highest->index = stack_size;
    }
}