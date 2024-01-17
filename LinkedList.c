#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};

struct node *insertAtBeginning(struct node *ptr, int val)
{
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->val = val;
    new->next = ptr;
    ptr = new;
    return ptr;
}

struct node *insertAtSpecific(struct node *ptr, int val, int pos)
{
    struct node *new = (struct node *) malloc(sizeof(struct node));
    struct node *temp1 = ptr;
    new->val = val;
    new->next = NULL;

    if(pos==1)
        return insertAtBeginning(ptr, val);
    
    while(pos>2 && temp1->next!=NULL)
    {
        temp1 = temp1->next;
        pos--;
    }
    new->next = temp1->next;
    temp1->next = new;
    return ptr;
}

struct node *insertAtEnd(struct node *ptr, int val)
{
    struct node *new = (struct node *) malloc(sizeof(struct node));
    struct node *temp = ptr;
    new->val = val;
    new->next = NULL;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = new;
    return ptr;
}

struct node *deleteAtPos(struct node *ptr, int pos)
{
    struct node *temp1 = ptr, *temp2 = temp1->next;
    if(ptr==NULL)
        printf("\nThe list is empty!");
    else if(pos==1)
    {
        temp1 = ptr;
        ptr = ptr->next;
        free(temp1);
    }
    else
    {
        while(pos>2 && temp1->next!=NULL)
        {
            temp1=temp1->next;
            temp2=temp1->next;
            pos--;
        }
        temp2 = temp1->next;
        temp1->next = temp1->next->next;
    }
    return ptr;
}

void display(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
    return;
}
int main()
{
    struct node *ptr=NULL;
    int choice, val, pos;
    while(1)
    {
        printf("\nEnter the choice:\n1. Insert at the Beginning\t2. Insert at the specific position\t3. Insert at the end\t4. Delete from the specific position\t5. Display\t0. Exit program\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: //to insert the value at beginning
                printf("\nEnter the value to insert: ");
                scanf("%d", &val);
                ptr = insertAtBeginning(ptr, val);
                break;
            case 2: //to insert the value at a specific position
                printf("\nEnter the value to insert: ");
                scanf("%d", &val);
                printf("\nEnter the position where to insert: ");
                scanf("%d", &pos);
                ptr = insertAtSpecific(ptr, val, pos);
                break;
            case 3: //to insert the value at end
                printf("\nEnter the value to insert: ");
                scanf("%d", &val);
                ptr = insertAtEnd(ptr, val);
                break;
            case 4: //to delete at the specific position
                printf("\nEnter the position of the node: ");
                scanf("%d", &pos);
                ptr = deleteAtPos(ptr, pos);
                break;
            case 5: //to display the whole linked list
                display(ptr);
                break;
            case 0:
                printf("\nExiting the program!");
                return 0;
            default:
                printf("\nInvalid Choice!");
        }
    }
}