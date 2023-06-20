#include "push_swap.h"

int	ft_isdigit(char arg)
{
	return (arg >= '0' && arg <= '9');
}

int ft_issign(char arg)
{
	return (arg == '+' || arg == '-');
}

void freeStack(t_list **stack)
{
    t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}


void exit_error(t_list **stack_a, t_list **stack_b)
{
    if(stack_a == NULL && *stack_a != NULL)
        freeStack(stack_a);
    if(stack_b == NULL && *stack_b != NULL)
        freeStack(stack_b);
    write(1, "Error\n", 6);
    exit(1);
}

long int	ft_atoi(const char *str)
{

	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}

void ft_putchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int ft_abs(int nb)
{
    if (nb < 0)
        return (nb * -1);
    else
        return (nb);
}
