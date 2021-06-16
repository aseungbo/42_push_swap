#ifndef MAIN_H
#define MAIN_H

#include <stdio.h> // only for test
#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
	int num;
	struct s_stack *prev;
	struct s_stack *next;
}				t_stack;


// util.c
int ft_strlen(char *str);
int ft_atoi(const char *str);

// command.c
void ft_swap(int *a, int *b);
int sab(t_stack **head);
int ss(t_stack **head1, t_stack **head2);
int pab(t_stack **head_from, t_stack **head_to);
int rab(t_stack **head);
int rr(t_stack **head1, t_stack **head2);
int rrab(t_stack **head);
int rrr(t_stack **head1, t_stack **head2);

#endif