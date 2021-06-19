#include "main.h"

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