/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:38:34 by seuan             #+#    #+#             */
/*   Updated: 2021/06/15 16:43:27 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int		sab(t_stack **head)
// {
//     t_stack *stack;

//     stack = *head;
//     if (stack && stack->next)
// 		pw_swap(&stack->num, &stack->next->num);
// 	return (0);
// }

// int		pab(t_stack **head_to, t_stack **head_from)
// {
// 	t_stack	*tmp;
// 	t_stack	*to;
// 	t_stack	*from;

// 	to = *head_to;
// 	from = *head_from;
// 	if (!from)
// 		return (0);
// 	tmp = from;
// 	from = from->next;
// 	*head_from = from;
// 	if (!to)
// 	{
// 		to = tmp;
// 		to->next = NULL;
// 		*head_to = to;
// 	}
// 	else
// 	{
// 		tmp->next = to;
// 		*head_to = tmp;
// 	}
// 	return (0);
// }

// int		rab()
// {
// 	return (0);
// }

// int		rrab()
// {
// 	return (0);
// }

// int		rab(t_stack **head)
// {
// 	t_stack	*tmp_first;
// 	t_stack	*tmp_last;
// 	t_stack	*stack;

// 	stack = *head;
// 	if (!(stack && stack->next))
// 		return (0);
// 	tmp_first = stack;
// 	stack = stack->next;
// 	tmp_last = stack;
// 	while (tmp_last->next)
// 	{
// 		tmp_last = tmp_last->next;
// 	}
// 	tmp_last->next = tmp_first;
// 	tmp_first->next = NULL;
// 	*head = stack;
// 	return (0);
// }

// int		rrab(t_stack **head)
// {
// 	t_stack	*tmp_last;
// 	t_stack	*previous;
// 	t_stack	*stack;

// 	stack = *head;
// 	if (!(stack && stack->next))
// 		return (0);
// 	tmp_last = stack;
// 	while (tmp_last->next)
// 	{
// 		previous = tmp_last;
// 		tmp_last = tmp_last->next;
// 	}
// 	tmp_last->next = stack;
// 	previous->next = NULL;
// 	*head = tmp_last;
// 	return (0);
// }