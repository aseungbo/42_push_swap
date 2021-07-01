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
			rab(a_stack, 'a');
			ra_cnt += 1;
		}
		else
		{
			pab(a_stack, b_stack, '>');
			pb_cnt += 1;
		}
		i++;
	}
	i = 0;
	while (i < ra_cnt)
	{
		rrab(a_stack, 'a');
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
		pab(b_stack, a_stack, '<');
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
			rab(b_stack, 'b');
			rb_cnt += 1;
		}
		else
		{
			pab(b_stack, a_stack, '<');
			pa_cnt += 1;
		}
		i++;
	}
	i = 0;
	while (i < rb_cnt)
	{
		rrab(b_stack, 'b');
		i++;
	}

	A_to_B(a_stack, b_stack, pa_cnt);
	B_to_A(a_stack, b_stack, rb_cnt);
}
