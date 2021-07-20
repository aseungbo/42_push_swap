/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elem_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:34:48 by seuan             #+#    #+#             */
/*   Updated: 2021/07/20 19:35:57 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack **a_stack, t_stack **b_stack, int len, t_global *global)
{
	int			mid;
	int			i;
	t_cnt_state	cnt_state;

	if (len == 1 || len == 2)
	{
		global->flag = 1;
		if (len == 2)
			sort_two(a_stack);
		return ;
	}
	cnt_state.ra_cnt = 0;
	cnt_state.pb_cnt = 0;
	mid = find_mid_value((*a_stack), len);
	i = -1;
	while (++i < len)
		a_to_b_sub(&cnt_state, &mid, a_stack, b_stack);
	i = -1;
	while (global->flag == 1 && ++i < cnt_state.ra_cnt)
		rrab(a_stack, 'a');
	a_to_b(a_stack, b_stack, cnt_state.ra_cnt, global);
	b_to_a(a_stack, b_stack, cnt_state.pb_cnt, global);
}

void	a_to_b_sub(t_cnt_state *cnt_state, \
							int *mid, t_stack **a_stack, t_stack **b_stack)
{
	if ((*a_stack)->num > *mid)
	{
		rab(a_stack, 'a');
		cnt_state->ra_cnt += 1;
	}
	else
	{
		pab(a_stack, b_stack, '>');
		cnt_state->pb_cnt += 1;
	}
}

void	b_to_a(t_stack **a_stack, t_stack **b_stack, int len, t_global *global)
{
	int			mid;
	int			i;
	t_cnt_state	cnt_state;

	if (len == 1)
	{
		pab(b_stack, a_stack, '<');
		return ;
	}
	cnt_state.pa_cnt = 0;
	cnt_state.rb_cnt = 0;
	mid = find_mid_value((*b_stack), len);
	i = -1;
	while (++i < len)
		b_to_a_sub(&cnt_state, &mid, a_stack, b_stack);
	i = -1;
	while (++i < cnt_state.rb_cnt)
		rrab(b_stack, 'b');
	a_to_b(a_stack, b_stack, cnt_state.pa_cnt, global);
	b_to_a(a_stack, b_stack, cnt_state.rb_cnt, global);
}

void	b_to_a_sub(t_cnt_state *cnt_state, \
							int *mid, t_stack **a_stack, t_stack **b_stack)
{
	if ((*b_stack)->num < *mid)
	{
		rab(b_stack, 'b');
		cnt_state->rb_cnt += 1;
	}
	else
	{
		pab(b_stack, a_stack, '<');
		cnt_state->pa_cnt += 1;
	}
}
