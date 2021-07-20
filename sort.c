/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:35:16 by seuan             #+#    #+#             */
/*   Updated: 2021/07/20 19:35:13 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_process(t_stack **stack1, t_stack **stack2, int len)
{
	t_global	*global;

	global = (t_global *)malloc(sizeof(t_global));
	global->flag = 0;
	if (len == 2)
		sort_two(stack1);
	else if (len == 3)
		sort_three(stack1);
	else if (len == 5)
		sort_five(stack1, stack2);
	else
		a_to_b(stack1, stack2, len_stack(*stack1), global);
	free(global);
}
