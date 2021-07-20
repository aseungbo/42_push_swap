/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elem_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:34:58 by seuan             #+#    #+#             */
/*   Updated: 2021/07/20 14:34:59 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stack **head)
{
	t_stack	*n1;
	t_stack	*n2;
	t_stack	*n3;

	n1 = *head;
	n2 = n1->next;
	n3 = n2->next;
	if (n1->num < n3->num && n3->num < n2->num)
	{
		rrab(head, 'a');
		sab(head, 'a');
	}
	else if (n2->num < n1->num && n1->num < n3->num)
		sab(head, 'a');
	else if (n2->num < n3->num && n3->num < n1->num)
		rab(head, 'a');
	else if (n3->num < n1->num && n1->num < n2->num)
		rrab(head, 'a');
	else if (n3->num < n2->num && n2->num < n1->num)
	{
		sab(head, 'a');
		rrab(head, 'a');
	}
	return (1);
}
