/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:34:34 by seuan             #+#    #+#             */
/*   Updated: 2021/07/20 15:51:32 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack		*stack1;
	t_stack		*stack2;
	t_global	global;
	int			len;

	global.argv = argv;
	global.argc = argc;
	stack1 = argv_to_stack(argc, &global);
	if (!(stack1))
		return (print_error());
	if (argc == 1)
		return (0);
	if (is_duplicate_num(&stack1))
		return (print_error());
	if (is_sorted_stack(&stack1))
		return (0);
	len = len_stack(stack1);
	stack2 = NULL;
	sort_process(&stack1, &stack2, len);
	return (0);
}
