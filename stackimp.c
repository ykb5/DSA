#include <stdio.h>
#include <stdlib.h>
#define MAX 6

void push(int n, int s[], int *top)
{
    if (*top >= MAX - 1)
        printf("\nThe Stack is Full.\n");
    else
    {
        *top = *top + 1;
        s[*top] = n;
    }
}
void pop(int s[], int *top)
{
    if (*top == -1)
    {
        printf("\nThe Stack is Empty.\n");
        exit(5);
    }
    else
    {
        printf("\nThe Deleted Element is: %d\n", s[*top]);
        *top = *top - 1;
    }
}
void peek(int s[], int *top)
{
    if (*top == -1)
        printf("\nThe Stack is Empty.\n");
    else
    {
        printf("\nThe Top Element is: %d\n", s[*top]);
    }
}
void replace(int s[], int *top, int m, int ind)
{
    if (*top == -1)
    {
        printf("\nThe Stack is Empty.\n");
    }
    else
    {
        s[ind - 1] = m;
    }
}
void display(int s[], int *top)
{
    int i = *top;
    printf("\nThe Stack elememts are: \n");
    for (; i >= 0; i--)
    {
        printf("%d ", s[i]);
    }
    printf("\n");
}

int main()
{
    int s[MAX], top = -1;
    int choice, n, m, ind;

    do
    {
        printf("Enter the choice: \n1. Push\n2. Pop\n3. Peek\n4. Replace\n5. Diplay\n0. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the Number to push: ");
            scanf("%d", &n);
            push(n, s, &top);
            break;
        case 2:
            pop(s, &top);
            break;
        case 3:
            peek(s, &top);
            break;
        case 4:
            printf("\nEnter the index: ");
            scanf("%d", &ind);
            printf("\nEnter the Number: ");
            scanf("%d", &m);
            replace(s, &top, m, ind);
            break;
        case 5:
            display(s, &top);
            break;
        case 0:
            return 0;
        default:
            printf("\nThe input is Invalid.\n");
        }

    } while (choice != 0);

    return 0;
}