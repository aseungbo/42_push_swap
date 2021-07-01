#include "main.h"

void current(t_stack *stack1, t_stack *stack2)
{
	t_stack *temp = stack1;
	t_stack *temp2 = stack2;
	
	puts("\n------------------------");
	printf("A stack: ");
	while (temp)
	{
		printf("%d ", temp->num);
		temp = temp->next;
	}
	printf("\n");
	printf("B stack: ");
	while (temp2)
	{
		printf("%d ", temp2->num);
		temp2 = temp2->next;
	}
	puts("\n------------------------");
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

	// 이미 정렬이 완료된 스택인 경우 에러 처리.
	if (is_sorted_stack(&stack1))
	{
		write(2, "Error\n", 6);
		return (0);
	}

	// 중복된 수인 경우 에러 처리
	if (is_duplicate_num(&stack1))
	{
		write(2, "Error\n", 6);
		return (0);
	}

	len = s_len(stack1);
	stack2 = NULL;

	if (len == 2)
		sort_two(&stack1);
	else if (len == 3)
		sort_three(&stack1);
	else if (len == 5)
	{
		printf("exec!\n");
		sort_five(&stack1, &stack2);
	}
	else
	{
		A_to_B(&stack1, &stack2, s_len(stack1));
		current(stack1, stack2);
	}
	return (0);
}