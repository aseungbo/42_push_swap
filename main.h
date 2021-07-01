#ifndef MAIN_H
#define MAIN_H

#include <stdio.h> // only for test
#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
	int 			num;
	struct s_stack	*next;
}				t_stack;

// util.c
void ft_swap(int *a, int *b);
int ft_strlen(char *str);
int ft_atoi(const char *str);
int	s_len(t_stack *stack);

// command.c
int sab(t_stack **head, char type);
int pab(t_stack **head_from, t_stack **head_to, char type);
int rab(t_stack **head, char type);
int rrab(t_stack **head, char type);
// int ss(t_stack **head1, t_stack **head2);
// int rr(t_stack **head1, t_stack **head2);
// int rrr(t_stack **head1, t_stack **head2);

// sort.c
void A_to_B(t_stack **a_stack, t_stack **b_stack, int len);
void B_to_A(t_stack **a_stack, t_stack **b_stack, int len);

// create_stack.c
t_stack *create_new_node(void);
void stack_del(t_stack *head);
t_stack *copy_args_in_stack(int argc, char **argv);

// pivot_helper
int		find_mid_value(t_stack *stack, int len);
int		*create_array_from_list(t_stack *stack, int len);
void	quick_sort(int *stack1, int start, int end);
int		partition(int *stack1, int start, int end);

// argv_error_check
int is_int_overflow(char *str);
int is_num(int k);
int is_error(char *str);
int	is_sorted_stack(t_stack **head);
int is_duplicate_num(t_stack **head);

//sort_under_three.c
int sort_two(t_stack **head);
int sort_three(t_stack **head);
int sort_five(t_stack **stack1, t_stack **stack2);

// FIX
void current(t_stack *stack1, t_stack *stack2); // only test!!

#endif
