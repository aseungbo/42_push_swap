#include "main.h"

int sort_two(t_stack **head)
{
    t_stack *n1 = *head;
    t_stack *n2 = n1->next;

    // printf("\n------ before ------\n");
    // printf("n1: %d\n", n1->num);
    // printf("n2: %d\n", n2->num);

    if (n1->num < n2->num)
    {
        // puts("\n case1");
    }
    else
    {
        // puts("\n case2");
        sab(head);
        write(1, "sa\n", 3);
    }

    // n1 = *head;
    // n2 = n1->next;
    // printf("\n------ after ------\n");
    // printf("n1: %d\n", n1->num);
    // printf("n2: %d\n", n2->num);
    return (1);
}

int sort_three(t_stack **head)
{
    t_stack *n1 = *head;
    t_stack *n2 = n1->next;
    t_stack *n3 = n2->next;

    // printf("\n------ before ------\n");
    // printf("n1: %d\n", n1->num);
    // printf("n2: %d\n", n2->num);
    // printf("n3: %d\n", n3->num);

    if (n1->num < n2->num && n2->num < n3->num)
    {
        // puts("\n case1");
    }
    else if (n1->num < n3->num && n3->num < n2->num)
    {
        // puts("\n case2");
        rrab(head);
        write(1, "rra\n", 4);
        sab(head);
        write(1, "sa\n", 3);
    }
    else if (n2->num < n1->num && n1->num < n3->num)
    {
        // puts("\n case3");
        sab(head);
        write(1, "sa\n", 3);
    }
    else if (n2->num < n3->num && n3->num < n1->num)
    {
        // puts("\n case4");
        rab(head);
        write(1, "ra\n", 3);
    }
    else if (n3->num < n1->num && n1->num < n2->num)
    {
        // puts("\n case5");
        rrab(head);
        write(1, "rra\n", 4);
    }
    else if (n3->num < n2->num && n2->num < n1->num)
    {
        // puts("\n case6");
        sab(head);
        write(1, "sa\n", 3);
        rrab(head);
        write(1, "rra\n", 4);
    }

    // n1 = *head;
    // n2 = n1->next;
    // n3 = n2->next;
    // printf("\n------ after ------\n");
    // printf("n1: %d\n", n1->num);
    // printf("n2: %d\n", n2->num);
    // printf("n3: %d\n", n3->num);
    return (1);
}

int sort_five(t_stack **stack1, t_stack **stack2)
{
    int pivot = find_mid_value(*stack1, 5);
    printf("aaaaaaa%d\n", pivot);
    t_stack *tmp = *stack1;
    t_stack *tmp2;

    current(*stack1, *stack2);
    int i = 0;
    while (i < 5)
    {
        if (tmp->num >= pivot)
        {
            tmp = tmp->next;
            rab(stack1);
            current(*stack1, *stack2);
        }
        else if (tmp->num < pivot)
        {
            pab(stack2, stack1);
            tmp = *stack1;
            current(*stack1, *stack2);
        }

        i++;
    }
    sort_three(stack1);

    tmp2 = *stack2;
    if (tmp2->num < tmp2->next->num)
        sab(stack2);
    
    pab(stack1, stack2);
    pab(stack1, stack2);
    current(*stack1, *stack2);

    return (0);
}