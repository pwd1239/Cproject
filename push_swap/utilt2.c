#include "push_swap.h"

int is_sorted(t_list **stack)
{
    t_list	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (-1);
		tmp = tmp->next;
	}
	return (1);

}

int ft_is_order(t_list **stack, int size)
{
    int	i;

	i = 0;
	while ((*stack)->index != 0)
	{
		rotate(stack);
		i++;
	}
	if (is_sorted(stack) == 1)
	{
		if (i > (size / 2))
		{
			if (size == 5 && i == 3)
				write(1, "rra\n", 4);
			write(1, "rra\n", 4);
		}
		else
			while (i-- > 0)
				write(1, "ra\n", 4);
		return (1);
	}
	else
		while (i-- > 0)
			reverse(stack);
	return (0);

}

void resetIndex(t_list **stack)
{
    t_list	*lst;

	lst = *stack;
	while (lst)
	{
		lst->index = -1;
		lst = lst->next;
	}
	assignIndex(stack);

}

void rotateToMin(t_list **stack, int size)
{
    int	i;

	i = 0;
	while ((*stack)->index != 0)
	{
		rotate(stack);
		i++;
	}
	if ((i > (size / 2)))
	{
		if (size == 5 && i == 3)
		    write(1, "rra\n", 4);
		write(1, "rra\n", 4);
	}
	else
	{
		while (i > 0)
		{
			write(1, "ra\n", 4);
			i--;
		}
	}

}

int	ft_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	write(fd, s, i);
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
		sign *= -1;
	i += (nptr[i] == '+' || nptr[i] == '-');
	while (ft_isdigit(nptr[i]))
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	res *= sign;
	return (res);
}

int	ft_isdigit(char arg)
{
	return (arg >= '0' && arg <= '9');
}

int	ft_isascii(int arg)
{
	return (arg >= 0 && arg <= 127);
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (8192);
	return (0);
}

long	ft_atob(const char *nptr)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
		sign *= -1;
	i += (nptr[i] == '+' || nptr[i] == '-');
	if (ft_isdigit(nptr[i]) == 0)
		return (LONG_MAX);
	while (ft_isdigit(nptr[i]))
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] && ft_isascii(nptr[i]))
		return (LONG_MAX);
	res *= sign;
	return (res);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

int	count_word(const char *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			++count;
			while (*s != c && *s)
				++s;
		}
		else
			++s;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	ptr = malloc (sizeof(char *) * (count_word(s, c) + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ptr[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*string;
	char			*ptr;
	size_t			i;
	size_t			slen;

	i = 0;
	string = (char *)s;
	slen = ft_strlen(string);
	if (start >= slen)
		return (ft_strdup(""));
	if (slen - start < len)
		len = slen - start;
	ptr = (char *)malloc (sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len && string[start + i] != '\0')
	{
		ptr[i] = string[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}