/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:31:37 by seuan             #+#    #+#             */
/*   Updated: 2021/06/15 15:30:49 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *tmp;

	// argv in stack
	tmp = args_in_stack(argc, argv);
	printf("tmp len: %d \n", s_len(tmp));
	return (0);
}