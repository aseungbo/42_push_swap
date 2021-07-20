/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:34:17 by seuan             #+#    #+#             */
/*   Updated: 2021/07/20 15:45:22 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_new_node(void)
{
	t_stack	*first;

	first = (t_stack *)malloc(sizeof(t_stack));
	first->num = 0;
	first->next = NULL;
	return (first);
}

void	stack_del(t_stack *head)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = head;
	tmp2 = head;
	while (tmp1)
	{
		tmp1 = tmp1->next;
		free(tmp2);
		tmp2 = tmp1;
	}
	head = NULL;
	free(head);
}

int	when_argv_many_num(t_global *global, \
				char **rst, t_stack **head, t_stack **tmp)
{
	int		i;
	int		len;

	i = 0;
	len = len_of_argv_arr(rst);
	if (global->idx == len_of_argv_arr(global->argv) - 1)
		len = len - 1;
	while (i < len)
	{
		if (is_error(rst[i]))
		{
			stack_del(*head);
			return (1);
		}
		(*tmp)->num = ft_atoi(rst[i]);
		if (i < len)
		{
			(*tmp)->next = create_new_node();
			(*tmp) = (*tmp)->next;
		}
		i++;
	}
	return (0);
}

int	when_argv_one_num(int i, char **argv, t_stack **head, t_stack **tmp)
{
	if (is_error(argv[i]))
	{
		stack_del(*head);
		return (1);
	}
	(*tmp)->num = ft_atoi(argv[i]);
	if (i < len_of_argv_arr(argv) - 1)
	{
		(*tmp)->next = create_new_node();
		(*tmp) = (*tmp)->next;
	}
	return (0);
}

t_stack	*argv_to_stack(int argc, t_global *global)
{
	int		i;
	char	**rst;
	t_stack	*head;
	t_stack	*tmp;

	i = 0;
	head = create_new_node();
	tmp = head;
	while (++i < argc)
	{
		global->idx = i;
		rst = ft_split(global->argv[i], ' ');
		if ((len_of_argv_arr(rst)) > 1)
		{
			if (when_argv_many_num(global, rst, &head, &tmp))
				return (0);
		}
		else
		{
			if (when_argv_one_num(i, global->argv, &head, &tmp))
				return (0);
		}
		all_free(rst);
	}
	return (head);
}
