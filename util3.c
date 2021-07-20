/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:35:27 by seuan             #+#    #+#             */
/*   Updated: 2021/07/20 14:35:27 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_of_argv_arr(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	all_free(char **rst)
{
	int	i;

	i = 0;
	while (rst[i])
	{
		free(rst[i]);
		i++;
	}
	free(rst);
}
