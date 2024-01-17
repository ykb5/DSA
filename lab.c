// Implementation of stack using linked list. And printing its element from bottom to top by using recursion.
//Yogesh Kumar Bhatt_H_20011189
#include <stdio.h>
#include <stdlib.h>

struct sNode
{
    char data;
    struct sNode *next;
};

void push(struct sNode **top_ref, int new_data)
{
    struct sNode *new_node = malloc(sizeof(struct sNode));
    if (new_node == NULL)
    {
        printf("Stack overflow \n");
        exit(0);
    }
    new_node->data = new_data;
    // link the old list
    // off the new node
    new_node->next = (*top_ref);
    // move the head to
    // point to the new node
    (*top_ref) = new_node;
}
int pop(struct sNode **top_ref)
{
    char res;
    struct sNode *top;
    // If stack is empty then error
    if (*top_ref == NULL)
    {
        printf("Stack overflow \n");
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}
int isEmpty(struct sNode *top)
{
    return (top == NULL) ? 1 : 0;
}
void print(struct sNode *top)
{
    printf("\n");
    while (top != NULL)
    {
        printf(" %d ", top->data);
        top = top->next;
    }
}
void insertAtBottom(struct sNode **top_ref, int item)
{
    if (isEmpty(*top_ref))
        push(top_ref, item);
    else
    {
        int temp = pop(top_ref);
        insertAtBottom(top_ref, item);
        push(top_ref, temp);
    }
}

void reverse(struct sNode **top_ref)
{
    if (!isEmpty(*top_ref))
    {
        int temp = pop(top_ref);
        reverse(top_ref);
        insertAtBottom(top_ref, temp);
    }
}

int main(void)
{
    struct sNode *st = NULL;
    int ch;
    int val;
    do
    {
        printf("\nMenu:\n1. Push\t2. Print\t3. Reverse Stack\t0. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            break;
        case 1:
            printf("Value : ");
            scanf("%d", &val);
            push(&st, val);
            break;
        case 2:
            if (st != NULL)
            {
                printf("Stack: ");
                print(st);
            }
            else
                printf("Stack is empty!\n");
            break;
        case 3:
            if (st != NULL)
            {
                printf("Reversed Stack: ");
                reverse(&st);
                print(st);
            }
            else
                printf("Stack is empty!\n");
            break;
        default:
            printf("\nInvalid Choice!\n");
        }
    } while (ch);

    free(st);
    return 0;
}