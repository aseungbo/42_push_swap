#include "main.h"

// void short_sort(t_stack **stack, int len)
// {
// 	if (len == 1)
// 		return ;
// }
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
	len = s_len(stack1);
	stack2 = NULL;

	// TEST sort_two & sort_three 
	// sort_two(&stack1);
	// sort_three(&stack1);

	// TEST print all A_stack & B_stack 

	current(stack1, stack2);

	A_to_B(&stack1, &stack2, s_len(stack1)); // CMD  
	
	current(stack1, stack2);

	// A_to_B(&stack1, &stack2, 8); // CMD  
	
	// current(stack1, stack2);

	// A_to_B(&stack1, &stack2, 4); // CMD  
	
	// current(stack1, stack2);

	// A_to_B(&stack1, &stack2, 2); // CMD  
	
	// current(stack1, stack2);

	// B_to_A(&stack1, &stack2, 4); // CMD  
	
	// current(stack1, stack2);
	
	// A_to_B(&stack1, &stack2, 3); // CMD  
	
	// current(stack1, stack2);
	
	// A_to_B(&stack1, &stack2, 3); // CMD  
	
	// current(stack1, stack2);




}