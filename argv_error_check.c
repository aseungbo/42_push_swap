/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:34:03 by seuan             #+#    #+#             */
/*   Updated: 2021/07/20 14:34:05 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int_overflow(char *str)
{
	char	*deadline;
	int		i;
	int		j;

	deadline = "2147483647";
	i = 0;
	if (str[0] == '-')
	{
		deadline = "2147483648";
		i++;
	}
	j = 0;
	while (j < 10)
	{
		if (deadline[j] < str[i])
			return (1);
		i++;
		j++;
	}
	return (0);
}

int	is_num(int k)
{
	if (k == '0' || k == '1' || k == '2' || k == '3' || k == '4'
		|| k == '5' || k == '6' || k == '7' || k == '8' || k == '9')
		return (1);
	return (0);
}

int	is_error(char *str)
{
	int		i;
	int		len;

	i = 0;
	if (str[i] == '-')
		i++;
	len = ft_strlen(&str[i]);
	if (len > 10)
		return (1);
	if (str[i] == '0' && is_num(str[i + 1]))
		return (1);
	while (str[i])
	{
		if (!is_num(str[i]))
			return (1);
		i++;
	}
	if (len == 10 && is_int_overflow(str))
		return (1);
	return (0);
}

int	is_duplicate_num(t_stack **head)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		len;

	tmp1 = *head;
	tmp2 = *head;
	while (tmp1)
	{
		tmp2 = *head;
		len = 0;
		while (tmp2)
		{
			if (tmp1->num == tmp2->num)
				len += 1;
			if (len > 1)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int	is_sorted_stack(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
