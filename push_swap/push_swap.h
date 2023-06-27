#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
    int data;
    int content;
    int index;
    struct s_list *next;
    struct s_list *prev;
}t_list;

void push(t_list **src, t_list **dst);
void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_a, t_list **stack_b);
void  reverse(t_list **stack);
void rra(t_list **stack);
void rrb(t_list **stack);
void rrr(t_list **stack_a, t_list **stack_b);
t_list *getTheMin(t_list **stack);
void  AssignIndex(t_list **stack);
int checkDuplicate(t_list *stack);
void freeStack(t_list **stack);
int stackInit(int ac, char **av, t_list **stack_a);
int getMaxBits_lst(t_list **stack);
int	lst_size(t_list *stack);
void radix_sort(t_list **stack_a, t_list **stack_b);
t_list	*lst_last(t_list *stack);
void rotate(t_list **stack);
void ra(t_list **stack);
void rb(t_list **stack);
void rr(t_list **stack_a, t_list **stack_b);
void sortThree(t_list **stack);
void sortFour(t_list **stack_a, t_list **stack_b);
void sort(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **a_stack, t_list **b_stack);
void	lst_addback(t_list **stack, t_list *news);
void ft_addFront(t_list **stack, t_list *new);
t_list	*lst_new(int content);
int is_sorted(t_list **stack);
int ft_is_order(t_list **stack, int size);
void resetIndex(t_list **stack);
void rotateToMin(t_list **stack, int size);
int	ft_putstr(char *s, int fd);
int	ft_atoi(const char *nptr);
int	ft_isdigit(char arg);
int	ft_isascii(int arg);
int	ft_isspace(int c);
long	ft_atob(const char *nptr);
void	free_split(char **split);
int	count_word(const char *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif