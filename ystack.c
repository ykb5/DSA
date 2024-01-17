#include <stdio.h>
#include <stdlib.h>
void push(int size, int stack[], int *top)
{
    int n;
    if(*top>=size-1)
        printf("\nThe stack is full.");
    else
    {
        printf("\nEnter the element: ");
        scanf("%d", &n);
        *top=*top+1;
        stack[*top]=n;
    }
    return;
}
void pop(int stack[], int *top)
{
    if(*top==-1)
        printf("\nThe stack is empty.");
    else
    {
        printf("\nThe popped element is: %d", stack[*top]);
        *top=*top-1;
    }
    return;
}
void peek(int stack[], int *top)
{
    if(*top==-1)
        printf("\nThe stack is empty.");
    else
        printf("\nThe top element is: %d", stack[*top]);
    return;
}
void replace(int stack[], int *top)
{
    int i, n;
    if(*top==-1)
        printf("\nThe stack is empty.");
    else
    {
        printf("\nEnter the index: ");
        scanf("%d", i);
        printf("\nEnter the element: ");
        scanf("%d", n);
        stack[i-1]=n;
    }
    return;
}
void display(int stack[], int *top)
{
    if(*top==-1)
        printf("\nThe stack is empty.");
    else
    {
        printf("\nThe elements of the stack are: ");
        for(int i=*top; i>=0; i--)
            printf("%d ", stack[i]);
    }
    return;
}
int main()
{
    int size;
    printf("\nEnter the size of stack: ");
    scanf("%d", &size);
    int stack[size], top=-1;
    int choice;
    do
    {
        printf("\nEnter the choice:\n1. Push\n2. Pop\n3. Peek\n4. Replace\n5. Display\n0. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                push(size, stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek(stack, &top);
                break;
            case 4:
                replace(stack, &top);
                break;
            case 5:
                display(stack, &top);
                break;
            case 0:
                return 0;
            default:
                printf("\nInvalid Choice!");
        }
    } while (choice!=0);
    
}

//@BKY