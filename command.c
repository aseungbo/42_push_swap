#include "main.h"

int		sab(t_stack **head, char type)
{
	t_stack	*stack;

	stack = *head;
	if (stack && stack->next)
		ft_swap(&stack->num, &stack->next->num);

	if (type == 'a')
        write(1, "sa\n", 3);
	else if (type == 'b')
		write(1, "sb\n", 3);
	return (0);
}


int		pab(t_stack **head_from, t_stack **head_to, char type)
{
	t_stack	*tmp;
	t_stack	*to;
	t_stack	*from;

	to = *head_to;
	from = *head_from;
	if (!from)
		return (0);
	tmp = from;
	from = from->next;
	*head_from = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		*head_to = to;
	}
	else
	{
		tmp->next = to;
		*head_to = tmp;
	}

	if (type == '>')
        write(1, "pb\n", 3);
	else if (type == '<')
		write(1, "pa\n", 3);
	return (0);
}

int		rab(t_stack **head, char type)
{
	t_stack	*tmp_first;
	t_stack	*tmp_last;
	t_stack	*stack;

	stack = *head;
	if (!(stack && stack->next))
		return (0);
	tmp_first = stack;
	stack = stack->next;
	tmp_last = stack;
	while (tmp_last->next)
	{
		tmp_last = tmp_last->next;
	}
	tmp_last->next = tmp_first;
	tmp_first->next = NULL;
	*head = stack;

	if (type == 'a')
        write(1, "ra\n", 3);
	else if (type == 'b')
		write(1, "rb\n", 3);
	return (0);
}

int		rrab(t_stack **head, char type)
{
	t_stack	*tmp_last;
	t_stack	*previous;
	t_stack	*stack;

	stack = *head;
	if (!(stack && stack->next))
		return (0);
	tmp_last = stack;
	while (tmp_last->next)
	{
		previous = tmp_last;
		tmp_last = tmp_last->next;
	}
	tmp_last->next = stack;
	previous->next = NULL;
	*head = tmp_last;

	if (type == 'a')
        write(1, "rra\n", 4);
	else if (type == 'b')
		write(1, "rrb\n", 4);
	return (0);
}

// int		ss(t_stack **stack1, t_stack **stack2)
// {
// 	sab(stack1, 'a');
// 	sab(stack2, 'b');
// 	write(1, "ss\n", 3);
// 	return (0);
// }

// int		rr(t_stack **stack1, t_stack **stack2)
// {
// 	rab(stack1, 'a');
// 	rab(stack2, 'b');
// 	write(1, "rr\n", 3);
// 	return (0);
// }

// int		rrr(t_stack **stack1, t_stack **stack2)
// {
// 	rrab(stack1, 'a');
// 	rrab(stack2, 'b');
// 	write(1, "rrr\n", 4);
// 	return (0);
// }
