/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:35:24 by seuan             #+#    #+#             */
/*   Updated: 2021/06/15 15:34:06 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_stack(t_stack **stack)
{
	t_stack	*del;
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*stack = NULL;
}

t_stack	*create_node(void)
{
	t_stack	*first;

	first = (t_stack *)malloc(sizeof(t_stack));
	first->num = 0;
	first->next = NULL;
	return (first);
}

t_stack	*args_in_stack(int argc, char **argv)
{
	int		i;
	t_stack	*first;
	t_stack	*tmp;

	i = 1;
	first = create_node();
	tmp = first;
	while (i < argc)
	{
		// 예외처리 값이 들어오면 NULL을 반환시킴.
		if (check_error(argv[i]))
		{
			del_stack(&first);
			return (NULL);
		}
		// 정상적인 값이 들어오면 argv를 숫자 자료형으로 변환 후 stack에 담는다.
		tmp->num = pw_atoi(argv[i]);
		printf("argv: %d \n", tmp->num);
		// 새 node를 만들어 다음 argv를 담기위한 준비를 한다.
		if (i < argc - 1)
		{
			tmp->next = create_node();
			tmp = tmp->next;
		}
		i++;
	}
	return (first);
}
