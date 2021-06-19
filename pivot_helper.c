#include "main.h"

int		find_mid_value(t_stack *stack, int len)
{
	int		*array;
	int		mid_value;

	len = s_len(stack) < len ? s_len(stack) : len;
	array = create_array_from_list(stack, len);
	quick_sort(array, 0, len - 1);
	mid_value = array[len / 2];
	free(array);
	return (mid_value);
}

int		*create_array_from_list(t_stack *stack, int len)
{
	int		*array;
	int		i;

	array = (int*)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		array[i] = stack->num;
		stack = stack->next;
		i++;
	}
	return (array);
}

int		partition(int *stack1, int start, int end)
{
	int	end_value;
	int	strt_indx;
	int	curr_indx;

	end_value = stack1[end];
	strt_indx = start - 1;
	curr_indx = start;
	while (curr_indx <= end - 1)
	{
		if (stack1[curr_indx] <= end_value)
		{
			strt_indx++;
			ft_swap(&stack1[strt_indx], &stack1[curr_indx]);
		}
		curr_indx++;
	}
	ft_swap(&stack1[strt_indx + 1], &stack1[end]);
	return (strt_indx + 1);
}

void	quick_sort(int *stack1, int start, int end)
{
	int	stack2[end + 1];
	int	top;
	int	pivot;

	top = -1;
	stack2[++top] = start;
	stack2[++top] = end;
	while (top >= 0)
	{
		end = stack2[top--];
		start = stack2[top--];
		pivot = partition(stack1, start, end);
		if (pivot - 1 > start)
		{
			stack2[++top] = start;
			stack2[++top] = pivot - 1;
		}
		if (pivot + 1 < end)
		{
			stack2[++top] = pivot + 1;
			stack2[++top] = end;
		}
	}
}