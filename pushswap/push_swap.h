#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

typedef struct s_list{
    int data; //data stored in the node
    void *content;
    struct s_list *next; //pointer to the next int the list
}t_list;


void display_error();
void  lst_check_int(t_list *stack_a, int check);
void isAscending(t_list *stack_a);
void isDescending(t_list *stack_a);
void ft_write_list(t_list **stack_a, int ac, char **av);
void ft_rrr_action_value(t_list **stack_a, t_list **stack_b, char *str);
void ft_ss_action_value(t_list **stack_a, t_list **stack_b, char *str);
void ft_ra_mouves(t_list **stack_a);
void ft_rb_mouves(t_list **stack_b);
void ft_rr_mouves(t_list **stack_a, t_list **stack_b);
void ft_sa_mouves(t_list **stack_a);
void ft_sb_mouves(t_list **stack_b);
void ft_ss_mouves(t_list **stack_a, t_list **stack_b);
void ft_pb_mouves(t_list **stack_a, t_list **stack_b);
#endif