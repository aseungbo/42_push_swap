/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:34:30 by seuan             #+#    #+#             */
/*   Updated: 2021/07/20 14:34:31 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mid_value(t_stack *stack, int len)
{
	int		*array;
	int		mid_value;

	array = create_array_from_list(stack, len);
	bubble_sort(array, len);
	mid_value = array[len / 2];
	free(array);
	return (mid_value);
}

int	*create_array_from_list(t_stack *stack, int len)
{
	int		*array;
	int		i;

	array = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		array[i] = stack->num;
		stack = stack->next;
		i++;
	}
	return (array);
}

void	bubble_sort(int *arr, int len)
{
	int		tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
