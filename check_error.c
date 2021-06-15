/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:21:25 by seuan             #+#    #+#             */
/*   Updated: 2021/06/15 17:29:09 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	doubles_checker(t_stack **stack)
// {
// 	int		*array;
// 	int		len;
// 	int		i;

// 	i = 0;
// 	len = s_len(*stack);
// 	array = create_array_from_list(*stack, len);
// 	quick_sort(array, 0, len - 1);
// 	while (i < len - 1)
// 	{
// 		if (array[i] >= array[i + 1])
// 		{
// 			stack_del(stack);
// 			free(array);
// 			return ;
// 		}
// 		i++;
// 	}
// 	free(array);
// }

int		check_int_overflow(char *str)
{
	if (str[0] == '-')
	{
		if (pw_atoi(str) > 0)
			return (1);
	}
	if (str[0] != '-')
	{
		if (pw_atoi(str) < 0)
			return (1);
	}
	return (0);
}

int		check_error(char *str)
{
	int		i;
	int		len;

	i = 0;
	if (str[i] == '-' && !pw_atoi(&str[i + 1]))
		return (1);
	if (str[i] == '-' && pw_atoi(&str[i + 1]))
		i++;
	len = pw_strlen(&str[i]);
	if (len > 10)
		return (1);
	// 문자 처리 수정
    while (str[i])
	{
		if (!pw_atoi(&str[i]))
        {
            // printf("str[i]: %c \n", str[i]);
			return (1);
        }
        // printf("str[i]: %c \n", str[i]);
		i++;
	}
    printf("str: %s\n", str);
	if (len == 10 && check_int_overflow(str))
		return (1);
	return (0);
}
