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

void insertatpos(struct node *ptr)
{
    struct node *temp=ptr, *new = (struct node *) malloc(sizeof(struct node));
    new->next = NULL;
    int n, num;
    if(ptr==NULL)
    {
        printf("\nThe list is empty.");
        return;
    }
    printf("\nEnter the position to insert: ");
    scanf("%d", &n);
    if(n==1)
        insertatbeginning(ptr);
    else
    {
        printf("\nEnter the number: ");
        scanf("%d", &num);
        while(n!=1)
        {
            temp=temp->next;
            n--;
        }
    }
    return;
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

void deleteatpos(struct node *ptr)
{
    struct node *temp=ptr, *temp2;
    int n;
    if(ptr==NULL)
    {
        printf("\nThe list is empty.");
        return;
    }
    printf("\nEnter the position of element to pop: ");
    scanf("%d", &n);
    if(n==1)
        ptr=temp->next;
    else
    {
        for(int i=1; i<n; i++)
        {
            temp2=temp;
            temp=temp->next;
        }
        temp2->next = temp->next;
    }
    printf("\nThe deleted element is: %d\n", temp->val);
    free(temp);
    return;
}

int main()
{
    struct node *ptr=NULL;
    int choice;
    while(1)
    {
        printf("\n1. Insertion at the beginning\n2. Insertion at the end\n3. Insertion at the specific position\n4. Delete specific node\n5. Display\n6. Delete duplicates\n0. Exit\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                ptr = insertatbeginning(ptr);
                break;
            case 2:
                ptr = insertatend(ptr);
                break;
            case 3:
                insertatpos(ptr);
                break;
            case 4:
                deleteatpos(ptr);
                break;
            case 5:
                display(ptr);
                break;
            case 0:
                return 0;
            deafult:
                printf("\nInvalid Choice.");
        }
    }
    
}

//@BKY