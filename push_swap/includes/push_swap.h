#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
    /* data */
    int data; //data stored in the node
    int index;
    int pos;
    int numOfRotation_a;
    int numOfRotation_b;
    int target_pos;
    struct s_list *next;
}t_list;


t_list *getTheBottom(t_list *stack);
void	ft_putstr(char *str);
void	push(t_list **src, t_list **dest);
t_list *get_stack_before_bottom(t_list *stack);
void rotate(t_list **stack);
void ft_ra_mouves(t_list **stack_a);
void ft_rb_mouves(t_list **stack_b);
void ft_rr_mouves(t_list **stack_a, t_list **stack_b);
void ft_rra_mouves(t_list **stack_a);
void ft_rrb_mouves(t_list **stack_b);
void ft_rrr_mouves(t_list **stack_a, t_list **stack_b);
void calculate_cost_value(t_list **stack_a, t_list **stack_b);
int	nbstr_cmp(const char *s1, const char *s2);
int  findTheHighestIndex(t_list *stack);
void calc_comb_to_find_cheapestMove(t_list **stack_a, t_list **stack_b);
int check_num(char *av);
int check_zero(char *av);
int ft_checkDuplicate(char **av);
int ft_isCorrectInput(char **av);
t_list *newStack(int data);
long int	ft_atoi(const char *str);
void exit_error(t_list **stack_a, t_list **stack_b);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list *fill_stack_a(int ac, char **av);
void assign_index(t_list *stack_a, int stack_size);
int check_isSorted(t_list *stack);
void ft_sortThreeElement(t_list **stack_a);
void push_expect_last_three(t_list **stack_a, t_list **stack_b);
void get_position(t_list **stack);
int get_target(t_list **stack_a, int index_b, int target_index, int target_pos);
void  targetPositionFound(t_list **stack_a, t_list **stack_b);
void ft_shiftStackToLowest(t_list **stack_a);
int getTheLOwestPosIndex(t_list **stack);
void ft_sortMoreThanThree(t_list **stack_a, t_list **stack_b);
void swaping(t_list **stack_a, t_list **stack_b, int stack_size);
void ft_rrr_mouves(t_list **stack_a, t_list **stack_b);
void rotate_both1(t_list **stack_a, t_list **stack_b, int *numOfRot_a, int *numOfRot_b);
void ft_rr_mouves(t_list **stack_a, t_list **stack_b);
void rotate_both2(t_list **stack_a, t_list **stack_b, int *numOfRot_a, int *numOfRot_b);
void rotate_stack_a(t_list **stack_a, int *numOfRotation);
void rotate_stack_b(t_list **stack_b, int *numOfRotation);
void ft_pa_mouve(t_list **stack_a, t_list **stack_b);
void ft_pb_move(t_list **stack_a, t_list **stack_b);
void move(t_list **stack_a, t_list **stack_b, int numOfRot_a, int numOfRot_b);
int	ft_lstsize(t_list *lst);
void ft_putchar(char *str);
void ft_ra_mouves(t_list **stack_a);
void ft_rb_mouves(t_list **stack_b);
void ft_sa(t_list **stack_a);
void ft_sb(t_list **stack_b);
void swap_stack(t_list *stack);
void ft_ss(t_list **stack_a, t_list **stack_b);
void ft_rra_mouves(t_list **stack_a);
void ft_rrb_mouves(t_list **stack_b);
void push_expect_last_three(t_list **stack_a, t_list **stack_b);
int ft_abs(int nb);
int	ft_isdigit(char arg);
int ft_issign(char arg);
void freeStack(t_list *stack);

#endif