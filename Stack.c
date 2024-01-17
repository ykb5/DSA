#include<stdio.h>

void push(int stack[], int size, int *top, int val)
{
    if(*top>=size-1)
        printf("\nThe stack is full!");
    else
    {
        *top = *top + 1;
        stack[*top] = val;
    }
    return;
}

void pop(int stack[], int *top)
{
    if(*top==-1)
        printf("\nThe stack is empty!");
    else
    {
        *top = *top - 1;
    }
    return;
}

void display(int stack[], int size, int top)
{
    if(top==-1)
        printf("\nThe stack is empty!");
    else
    {
        printf("\nThe Stack elements are: ");
        while(top!=-1)
        {
            printf("%d ", stack[top]);
            top = top -1;
        }
        return;
    }
}

int main()
{
    int choice, val, size, top=-1;

    printf("\nEnter the size of the Stack: ");
    scanf("%d", &size);
    int stack[size];

    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: //push
                printf("\nEnter the element: ");
                scanf("%d", &val);
                push(stack, size, &top, val);
                break;
            case 2: //pop
                pop(stack, &top);
                break;
            case 3: //display
                display(stack, size, top);
                break;
            case 0: //exit
                printf("\nExiting the program!");
                return 0;
            default:
                printf("\nInvalid Choice!");
                break;
        }
    }
}