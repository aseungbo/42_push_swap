#include "main.h"

void A_to_B(t_stack **a_stack, t_stack **b_stack, int len)
{
	int	mid;
	int i;
	int ra_cnt;
	int pb_cnt;

	if (len == 1)
		return ;
	if (len == 2)
	{
		sort_two(a_stack);
		return;
	}

	ra_cnt = 0;
	pb_cnt = 0;
	mid = find_mid_value((*a_stack), len);

	i = 0;
	while (i < len)
	{
		if ((*a_stack)->num > mid)
		{
			rab(a_stack);
			write(1, "ra\n", 3);
			ra_cnt += 1;
		}
		else
		{
			pab(b_stack, a_stack);
			write(1, "pb\n", 3);
			pb_cnt += 1;
		}
		i++;
	}
	i = 0;
	while (i < ra_cnt)
	{
		rrab(a_stack);
		write(1, "rra\n", 4);
		i++;
	}
	A_to_B(a_stack, b_stack, ra_cnt);
	B_to_A(a_stack, b_stack, pb_cnt);
}

void B_to_A(t_stack **a_stack, t_stack **b_stack, int len)
{
	int	mid;
	int i;
	int pa_cnt;
	int rb_cnt;
	
	if (len == 1)
	{
		pab(a_stack, b_stack);
		write(1, "pa\n", 3);
		return ;
	}

	pa_cnt = 0;
	rb_cnt = 0;
	mid = find_mid_value((*b_stack), len);

	i = 0;
	while (i < len)
	{
		if ((*b_stack)->num < mid)
		{
			rab(b_stack);
			write(1, "rb\n", 3);
			rb_cnt += 1;
		}
		else
		{
			pab(a_stack, b_stack);
			write(1, "pa\n", 3);
			pa_cnt += 1;
		}
		i++;
	}
	i = 0;
	while (i < rb_cnt)
	{
		rrab(b_stack);
		write(1, "rrb\n", 4);
		i++;
	}

	A_to_B(a_stack, b_stack, pa_cnt);
	B_to_A(a_stack, b_stack, rb_cnt);
}
