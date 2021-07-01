#include "main.h"

int sort_two(t_stack **head)
{
    t_stack *n1 = *head;
    t_stack *n2 = n1->next;

    if (n1->num > n2->num)
    {
        sab(head);
        write(1, "sa\n", 3);
    }

    return (1);
}

int sort_three(t_stack **head)
{
    t_stack *n1 = *head;
    t_stack *n2 = n1->next;
    t_stack *n3 = n2->next;

    if (n1->num < n3->num && n3->num < n2->num)
    {
        rrab(head);
        write(1, "rra\n", 4);
        sab(head);
        write(1, "sa\n", 3);
    }
    else if (n2->num < n1->num && n1->num < n3->num)
    {
        sab(head);
        write(1, "sa\n", 3);
    }
    else if (n2->num < n3->num && n3->num < n1->num)
    {
        rab(head);
        write(1, "ra\n", 3);
    }
    else if (n3->num < n1->num && n1->num < n2->num)
    {
        rrab(head);
        write(1, "rra\n", 4);
    }
    else if (n3->num < n2->num && n2->num < n1->num)
    {
        sab(head);
        write(1, "sa\n", 3);
        rrab(head);
        write(1, "rra\n", 4);
    }

    return (1);
}

int sort_five(t_stack **stack1, t_stack **stack2)
{
    int pivot = find_mid_value(*stack1, 5);
    t_stack *tmp = *stack1;
    t_stack *tmp2;

    int i = 0;
    while (i < 5)
    {
        if (tmp->num >= pivot)
        {
            tmp = tmp->next;
            rab(stack1);
        }
        else if (tmp->num < pivot)
        {
            pab(stack1, stack2);
            tmp = *stack1;
        }
        i++;
    }
    sort_three(stack1);
    tmp2 = *stack2;
    if (tmp2->num < tmp2->next->num)
        sab(stack2);
    pab(stack2, stack1);
    pab(stack2, stack1);

    return (0);
}