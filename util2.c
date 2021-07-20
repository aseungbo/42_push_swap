/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seuan <seuan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:35:24 by seuan             #+#    #+#             */
/*   Updated: 2021/07/20 14:35:24 by seuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	count_words(char *str, char sep)
{
	long long	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && *str == sep)
			str++;
		if (*str && *str != sep)
		{
			cnt++;
			while (*str && *str != sep)
				str++;
		}
	}
	return (cnt);
}

char	*malloc_word(char *str, char sep)
{
	char		*word;
	int			i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != sep)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	*leak(char **rst, int words)
{
	int			i;

	i = 0;
	while (i < words)
	{
		free(rst[i]);
		i++;
	}
	free(rst);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**rst;
	int			i;

	rst = (char **)malloc(sizeof(char *) * (count_words((char *)s, c) + 1));
	if (!rst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			rst[i] = malloc_word((char *)s, c);
			if (!(rst[i]))
				return (leak(rst, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	rst[i] = NULL;
	return (rst);
}
