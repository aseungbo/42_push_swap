/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elem_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:35:11 by seuan             #+#    #+#             */
/*   Updated: 2021/07/20 14:35:12 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_two(t_stack **head)
{
	t_stack	*n1;
	t_stack	*n2;

	n1 = *head;
	n2 = n1->next;
	if (n1->num > n2->num)
		sab(head, 'a');
	return (1);
}