/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:32:59 by seuan             #+#    #+#             */
/*   Updated: 2021/06/15 16:51:15 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
// Delete bottom lines. after testing !
// unnecessary library
#include <stdio.h>

// 이중 원형 연결 리스트 구현.
// 노드 개별
typedef struct		s_stack
{
	int				num;
    // struct s_stack* prev; // 이전 노드를 가리킬 포인터
    // struct s_stack* next; // 다음 노드를 가리킬 포인터
	struct s_stack	*next;
}					t_stack;

void    pw_swap(int *a, int *b);
int     check_error(char *str);
int		pw_atoi(const char *nptr);
int     s_len(t_stack *stack);
size_t	pw_strlen(const char *s);
t_stack	*args_in_stack(int argc, char **argv);

#endif
