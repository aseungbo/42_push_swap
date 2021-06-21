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
        sab(head, 'a');
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
        rrab(head, 'a');
        sab(head, 'a');
    }
    else if (n2->num < n1->num && n1->num < n3->num)
    {
        // puts("\n case3");
        sab(head, 'a');
    }
    else if (n2->num < n3->num && n3->num < n1->num)
    {
        // puts("\n case4");
        rab(head, 'a');
    }
    else if (n3->num < n1->num && n1->num < n2->num)
    {
        // puts("\n case5");
        rrab(head, 'a');
    }
    else if (n3->num < n2->num && n2->num < n1->num)
    {
        // puts("\n case6");
        sab(head, 'a');
        rrab(head, 'a');
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