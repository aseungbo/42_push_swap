/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:34:42 by seuan             #+#    #+#             */
/*   Updated: 2021/07/20 15:45:07 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_global
{
	char			**argv;
	int				argc;
	int				idx;
}					t_global;

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

typedef struct s_cnt_state
{
	int				ra_cnt;
	int				pb_cnt;
	int				rb_cnt;
	int				pa_cnt;
}					t_cnt_state;

void				ft_swap(int *a, int *b);
int					ft_strlen(char *str);
int					ft_atoi(const char *str);
int					len_stack(t_stack *stack);
int					len_of_argv_arr(char **str);
char				**ft_split(char const *s, char c);
int					sab(t_stack **head, char type);
int					pab(t_stack **head_from, t_stack **head_to, char type);
int					rab(t_stack **head, char type);
int					rrab(t_stack **head, char type);
void				a_to_b(t_stack **a_stack, t_stack **b_stack, int len);
void				a_to_b_sub(t_cnt_state *cnt_state, \
								int *mid, t_stack **a_stack, t_stack **b_stack);
void				b_to_a(t_stack **a_stack, t_stack **b_stack, int len);
void				b_to_a_sub(t_cnt_state *cnt_state, \
								int *mid, t_stack **a_stack, t_stack **b_stack);
void				sort_process(t_stack **stack1, t_stack **stack2, int len);
t_stack				*create_new_node(void);
void				stack_del(t_stack *head);
t_stack				*argv_to_stack(int argc, t_global *global);
int					find_mid_value(t_stack *stack, int len);
int					*create_array_from_list(t_stack *stack, int len);
void				bubble_sort(int *stack1, int count);
int					is_int_overflow(char *str);
int					is_num(int k);
int					is_error(char *str);
int					is_sorted_stack(t_stack **head);
int					is_duplicate_num(t_stack **head);
int					sort_two(t_stack **head);
int					sort_three(t_stack **head);
int					sort_five(t_stack **stack1, t_stack **stack2);
void				all_free(char **rst);
void				sort_five_a_stack(t_stack **stack1, t_stack **stack2, \
										int pivot);
void				sort_five_b_stack(t_stack **stack1, t_stack **stack2);

#endif
