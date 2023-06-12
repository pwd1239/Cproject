#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (!lst)	
		return (0);
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void ft_putchar(char *str)
{
	int i;
	
	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_isdigit(char arg)
{
	return (arg >= '0' && arg <= '9');
}

int ft_issign(char arg)
{
	return (arg == '+' || arg == '-');
}

int ft_abs(int nb)
{
    if (nb < 0)
        return (nb * -1);
    else
        return (nb);
}

long int	ft_atoi(const char *str)
{
	long int	nbr;
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

void freeStack(t_list *stack)
{
    while (stack != NULL)
	{
        t_list *temp = stack;
        stack = stack->next;
        free(temp); // Free the current node
    }
}


void exit_error(t_list **stack_a, t_list **stack_b)
{
    if(stack_a == NULL && *stack_a != NULL)
        freeStack(*stack_a);
    if(stack_b == NULL && *stack_b != NULL)
        freeStack(*stack_b);
    write(1, "Error\n", 6);
    exit(1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}