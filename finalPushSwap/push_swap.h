#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#define INT_MAX
#define INT_MIN

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

void calculate_cost_value(t_list **stack_a, t_list **stack_b);
void calc_comb_to_find_cheapestMove(t_list **stack_a, t_list **stack_b);
void calc_comb_to_find_cheapestMove(t_list **stack_a, t_list **stack_b);
static int check_num(char *av);
static int check_zero(char *av);
bool ft_checkDuplicate(char *av);
int ft_isCorrectInput(char *av);
t_list *newStack(int data);
int	ft_atoi(const char *str);
void exit_error(t_list **stack_a, t_list **stack_b);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list fill_stack_a(int ac, char **av);
void assign_index(t_list *stack_a, int stack_size);
int check_isSorted(t_list *stack);
void ft_sortThreeElement(t_list **stack_a);
void push_expect_last_three(t_list **stack_a, t_list **stack_b);
void get_position(t_list **stack);
void get_target(t_list **stack_a, int index_b, int target_index, int target_pos);
int  targetPositionFound(t_list **stack_a, t_list **stack_b);
void ft_shiftStackToLowest(t_list **stack_a);
void getTheLOwestPosIndex(t_list **stack);
void ft_sortMoreThanThree(t_list **stack_a, t_list **stack_b);
void swap(t_list **stack_a, t_list **stack_b, int stack_size);
void ft_sa_moves(t_list **stack_a);
void ft_sb_moves(t_list **stack_b);
void ft_rrr_mouves(t_list **stack_a, t_list **stack_b);
void rotate_both1(t_list **stack_a, t_list **stack_b, int *numOfRot_a, int *numOfRot_b);
void ft_rr_mouves(t_list **stack_a, t_list **stack_b);
void rotate_both1(t_list **stack_a, t_list **stack_b, int *numOfRot_a, int *numOfRot_b);
void rotate_both2(t_list **stack_a, t_list **stack_b, int *numOfRot_a, int *numOfRot_b);
void rotate_stack_a(t_list *stack_a, int *numOfRotation);
void rotate_stack_b(t_list *stack_b, int *numOfRotation);
void ft_pa_move(t_list **stack_a, t_list **stack_b);
void ft_pb_move(t_list **stack_a, t_list **stack_b);
void move(t_list **stack_a, t_list **stack_b, int numOfRot_a, int numOfRot_b);
int	ft_lstsize( t_list *lst);
void ft_putchar(char *str);

#endif