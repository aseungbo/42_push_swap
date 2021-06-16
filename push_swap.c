#include "main.h"

int		s_len(t_stack *stack)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

t_stack *create_new_node(void)
{
	t_stack *first;

	first = (t_stack *)malloc(sizeof(t_stack));
	first->num = 0;
	first->prev = NULL;
	first->next = NULL;
	return (first);
}

void stack_del(t_stack *head)
{
	t_stack *tmp1;
	t_stack *tmp2;

	tmp1 = head;
	tmp2 = head;
	while (tmp1)
	{
		tmp1 = tmp1->next;
		free(tmp2);
		tmp2 = tmp1;
	}
	head = NULL;
}

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
	if (k == '0' || k == '1' || k == '2' || k == '3' || k == '4')
		return (1);
	if (k == '5' || k == '6' || k == '7' || k == '8' || k == '9')
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

t_stack *copy_args_in_stack(int argc, char **argv)
{
	// 처음 받은 인자를 스택에 넣는 로직.
	int i;
	t_stack *head;
	t_stack *tmp;

	i = 1;
	head = create_new_node();
	tmp = head;
	while (i < argc)
	{
		// 에러 인자값이 들어오는 경우 기존에 할당한 메모리 해제.
		if (is_error(argv[i]))
		{
			stack_del(head);
			return (NULL);
		}

		tmp->num = ft_atoi(argv[i]);

		// 새 노드를 생성해가면서 양방향 바인딩.
		if (i < argc - 1)
		{
			tmp->next = create_new_node();
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
		i++;
	}
	return (head);
}

void short_sort(t_stack **stack, int len)
{
	if (len == 1)
		return ;
}

// int		find_mid_value(t_stack *stack, int len)
// {
// 	int		*array;
// 	int		mid_value;

// 	len = s_len(stack) < len ? s_len(stack) : len;
// 	array = create_array_from_list(stack, len);
// 	quick_sort(array, 0, len - 1);
// 	mid_value = array[len / 2];
// 	free(array);
// 	return (mid_value);
// }

// 5 2 3 1 4

// [5 2 3 1 4]

// [1, 2, 3, 4, 5]

// 	  1
//       3
// 4     2
// 5

// def A_to_B()
// 	스택A 원소 중에서 "적절한" 피봇을 선택한다
// 	for r개의 원소에 대해서
// 		if (스택A의 top) > 피봇 #top은 스택의 최상단 값
// 			ra명령으로 뒤로 넘긴다
// 		else
// 			pb명령으로 b로 보낸다

void A_to_B(t_stack **a_stack, t_stack **b_stack, int len)
{
	// t_stack *tmp1;
	// t_stack *tmp2;
	int	mid;
	int i;

	// tmp1 = a_stack;
	// tmp2 = b_stack;
	// mid = find_mid_value(a_stack, len); //3
	mid = 3;
	i = 0;
	while (i < len)
	{
		// printf("tmp1: %d\n", tmp1->num);
		if ((*a_stack)->num > mid)
			rab(a_stack);
		else
			pab(b_stack, a_stack);
		// tmp1 = tmp1->next;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_stack *stack1;
	t_stack *stack2;
	int		len;

	// stack1 에 받은 인자값들 복사.
	if (!(stack1 = copy_args_in_stack(argc, argv)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	len = s_len(stack1);
	stack2 = NULL;

	// test
	t_stack *temp = stack1;
	t_stack *temp2 = stack2;
	printf("------------- before commands -----------\n");
	while (temp)
	{
		printf("%d", temp->num);
		temp = temp->next;
	}
	printf("\n");
	while (temp2)
	{
		printf("%d", temp2->num);
		temp2 = temp2->next;
	}
	printf("\n");
	printf("------------- after commands -----------\n");
	// commands
	A_to_B(&stack1, &stack2, len);
	
	// test
	temp = stack1;
	temp2 = stack2;
	while (temp)
	{
		printf("%d", temp->num);
		temp = temp->next;
	}
	printf("\n");
	while (temp2)
	{
		printf("%d", temp2->num);
		temp2 = temp2->next;
	}
	printf("\n");
}