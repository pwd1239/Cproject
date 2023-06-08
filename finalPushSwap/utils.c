#include "push_swap.h"

int	ft_lstsize( t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return ;
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

int	ft_isdigit(int arg)
{
	return (arg >= '0' && arg <= '9');
}

