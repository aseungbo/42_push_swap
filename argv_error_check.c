#include "main.h"

int is_int_overflow(char *str)
{
	// 앞에서부터 deadline과 비교하여 자리값이 하나라도 크면 에러처리.
	char *deadline;
	int i;
	int j;

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

int is_num(int k)
{
	if (k == '0' || k == '1' || k == '2' || k == '3' || k == '4' || k == '5' || k == '6' || k == '7' || k == '8' || k == '9')
		return (1);
	return (0);
}

int is_error(char *str)
{
	int i;
	int len;

	i = 0;
	if (str[i] == '-')
		i++;
	// 숫자가 10자리 넘어가면 에러처리.
	len = ft_strlen(&str[i]);
	if (len > 10)
		return (1);
	// 0이 숫자의 맨처음으로 나오는 경우 에러처리.
	if (str[i] == '0' && is_num(str[i + 1]))
		return (1);
	// 문자열의 모든 부분이 수로 이루어져있는지 체크.
	while (str[i])
	{
		if (!is_num(str[i]))
			return (1);
		i++;
	}
	// 문자열로 들어온 수가 오버플로우이면 에러처리.
	if (len == 10 && is_int_overflow(str))
		return (1);
	return (0);
}

int	is_sorted_stack(t_stack **head)
{
	t_stack *n1 = *head;
    t_stack *n2 = n1->next;

	while (s_len(n1) - 1)
	{
		if (n1->num > n2->num)
			return (0);
		n1 = n1->next;
		n2 = n2->next;
	}
	return (1);
}

int is_duplicate_num(t_stack **head)
{
	t_stack *n1 = *head;
	t_stack *n2 = n1->next;

	while (s_len(n1))
	{
		while (s_len(n2))
		{
			if (n2->num == n1->num)
				return (1);
			n2 = n2->next;
		}
		n1 = n1->next;
	}
	return (0);
}
