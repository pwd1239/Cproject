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
int	ft_lstsize( t_list *lst);
void ft_rrr_mouves(t_list **stack_a, t_list **stack_b);
void rotate_both(t_list **stack_a, t_list **stack_b, int *numOfRot_a, int *numOfRot_b);
void move(t_list **stack_a, t_list **stack_b, int numOfRot_a, int numOfRot_b);

#endif