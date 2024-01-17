#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct node *insertatbeginning(struct node *ptr)
{
    struct node *new=(struct node *) malloc(sizeof(struct node));
    int n;
    new->next = NULL;
    printf("\nEnter the number: ");
    scanf("%d", &n);
    new->val = n;
    if(ptr == NULL)
        ptr = new;
    else
    {
        new->next = ptr;
        ptr = new;
    }
    return ptr;
}

struct node *insertatend(struct node *ptr)
{
    struct node *temp, *new = (struct node *) malloc(sizeof(struct node));
    int n;
    new->next = NULL;
    temp = ptr;
    printf("\nEnter the number: ");
    scanf("%d", &n);
    new->val=n;
    if(ptr==NULL)
        ptr = new;
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = new;
    }
    return ptr;
}

void display(struct node *ptr)
{
    struct node *dis=ptr;
    if(dis==NULL)
    {
        printf("\nThe list is empty.");
        return;
    }
    while(dis!=NULL)
    {
        printf("%d ", dis->val);
        dis = dis->next;
    }
    printf("\n");
    return;
}

void insertatpos(struct node *ptr)
{
    return;
}

struct node duplicate(struct node *ptr)
{
    struct node *temp=ptr, *temp2, *temp3=ptr;
    if(ptr==NULL)
    {
        printf("\nThe list is empty.");
        return;
    }
    while(temp!=NULL)
    {
        temp2=temp->next;
        while(temp2!=NULL)
        {
            if(temp->val==temp2->val)
            {
                temp2=delete(ptr, temp2);
            }
            else
            {
                temp3=temp2;
                temp2=temp2->next;
            }
        }
        temp=temp->next;
    }
    return;
}

struct node delete(struct node *ptr, struct node *temp)
{
    struct node *temp1=ptr, *temp2;
    while(temp1!=temp)
    {
        temp2=temp1;
        temp1=temp1->next;
    }
    temp2->next = temp1->next;
    printf("\nThe deleted element is: %d\n", temp1->val);
    free(temp1);
    return (temp2->next);
}

int main()
{
    struct node *ptr=NULL;
    int choice;
    while(1)
    {
        printf("\n1. Insertion at the beginning\n2. Insertion at the end\n5. Display\n6. Delete duplicates\n0. Exit\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                ptr = insertatbeginning(ptr);
                break;
            case 2:
                ptr = insertatend(ptr);
                break;
            case 5:
                display(ptr);
                break;
            case 6:
                duplicate(ptr);
                break;
            case 0:
                return 0;
            deafult:
                printf("\nInvalid Choice.");
        }
    }
    
}

//@BKY