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
	if (len == 3)
	{
		sort_three(a_stack);
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
			ra_cnt += 1;
		}
		else
		{
			pab(b_stack, a_stack);
			pb_cnt += 1;
		}
		i++;
	}
	i = 0;
	while (i < ra_cnt)
	{
		rrab(a_stack);
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
			rb_cnt += 1;
		}
		else
		{
			pab(a_stack, b_stack);
			pa_cnt += 1;
		}
		i++;
	}
	i = 0;
	while (i < rb_cnt)
	{
		rrab(b_stack);
		i++;
	}

	A_to_B(a_stack, b_stack, pa_cnt);
	B_to_A(a_stack, b_stack, rb_cnt);
}

// def B_to_A(범위의 크기r)
// 	스택B의 r개의 원소 중에서 "적절한" 피봇을 선택한다
// 	for r개의 원소에 대해서
// 		if (스택B의 top) > 피봇
// 			rb명령으로 뒤로 넘긴다
// 			rb_호출_횟수++
// 		else
// 			pa명령으로 a로 보낸다
// 			pa_호출_횟수++
// 	for ra_호출 횟수
// 		rra #ra로 넘어간 원소들을 다시 스택 상단으로 되감기

// void B_to_A(t_stack **a_stack, t_stack **b_stack, int len)
// {
// 	int	mid;
// 	int i;

// 	mid = find_mid_value((*b_stack), len);
// 	i = 0;
// 	while (i < len)
// 	{
// 		if ((*b_stack)->num > mid)
//     // rb_호출_횟수++
// 			rab(b_stack);
// 		else
//     // pa_호출_횟수++
// 			pab(a_stack, b_stack);
// 		i++;
// 	}
// }