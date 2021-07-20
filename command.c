/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:34:10 by seuan             #+#    #+#             */
/*   Updated: 2021/07/20 14:34:12 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_pab(char type)
{
	if (type == '>')
		write(1, "pb\n", 3);
	else if (type == '<')
		write(1, "pa\n", 3);
}

int	sab(t_stack **head, char type)
{
	t_stack	*stack;

	stack = *head;
	if (stack && stack->next)
		ft_swap(&stack->num, &stack->next->num);
	if (type == 'a')
		write(1, "sa\n", 3);
	else if (type == 'b')
		write(1, "sb\n", 3);
	return (0);
}

int	pab(t_stack **head_from, t_stack **head_to, char type)
{
	t_stack	*tmp;
	t_stack	*to;
	t_stack	*from;

	to = *head_to;
	from = *head_from;
	if (!from)
		return (0);
	tmp = from;
	from = from->next;
	*head_from = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		*head_to = to;
	}
	else
	{
		tmp->next = to;
		*head_to = tmp;
	}
	display_pab(type);
	return (0);
}

int	rab(t_stack **head, char type)
{
	t_stack	*tmp_first;
	t_stack	*tmp_last;
	t_stack	*stack;

	stack = *head;
	if (!(stack && stack->next))
		return (0);
	tmp_first = stack;
	stack = stack->next;
	tmp_last = stack;
	while (tmp_last->next)
	{
		tmp_last = tmp_last->next;
	}
	tmp_last->next = tmp_first;
	tmp_first->next = NULL;
	*head = stack;
	if (type == 'a')
		write(1, "ra\n", 3);
	else if (type == 'b')
		write(1, "rb\n", 3);
	return (0);
}

int	rrab(t_stack **head, char type)
{
	t_stack	*tmp_last;
	t_stack	*previous;
	t_stack	*stack;

	stack = *head;
	if (!(stack && stack->next))
		return (0);
	tmp_last = stack;
	while (tmp_last->next)
	{
		previous = tmp_last;
		tmp_last = tmp_last->next;
	}
	tmp_last->next = stack;
	previous->next = NULL;
	*head = tmp_last;
	if (type == 'a')
		write(1, "rra\n", 4);
	else if (type == 'b')
		write(1, "rrb\n", 4);
	return (0);
}
