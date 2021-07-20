/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elem_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:34:53 by seuan             #+#    #+#             */
/*   Updated: 2021/07/20 14:34:54 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_five(t_stack **stack1, t_stack **stack2)
{
	int		pivot;

	pivot = find_mid_value(*stack1, 5);
	sort_five_a_stack(stack1, stack2, pivot);
	sort_three(stack1);
	sort_five_b_stack(stack1, stack2);
	return (0);
}

void	sort_five_a_stack(t_stack **stack1, t_stack **stack2, int pivot)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack1;
	i = -1;
	while (++i < 5)
	{
		if (tmp->num >= pivot)
		{
			tmp = tmp->next;
			rab(stack1, 'a');
		}
		else if (tmp->num < pivot)
		{
			pab(stack1, stack2, '>');
			tmp = *stack1;
		}
	}
}

void	sort_five_b_stack(t_stack **stack1, t_stack **stack2)
{
	t_stack		*tmp;

	tmp = *stack2;
	if (tmp->num < tmp->next->num)
		sab(stack2, 'b');
	pab(stack2, stack1, '<');
	pab(stack2, stack1, '<');
}
