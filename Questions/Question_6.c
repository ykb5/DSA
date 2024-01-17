/*Q6. Write a C Program to create  singly linked list by adding nodes in the right hand side and delete alternate node from the list and then print  the final list.*/
#include<stdio.h> 
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

void insertAtRightSide(node **,int);
void deleteAtAlternate(node*);
void display(node *head);
 int main() 
 {
 printf("Himanshu Chauhan F 20011493\n");
 node *head;
int counter=0,choice,value,pos;

head=NULL;
while(counter==0)
{

printf("1.INSERT AT RIGHT \n2.DELETE ALTERNATE NODES \n3.DISPLAY \n4.EXIT\n");
scanf("%d",&choice);

switch(choice)
{
case 1:
printf("Enter a value : ");
scanf("%d",&value);
insertAtRightSide(&head,value);
break;

case 2:
deleteAtAlternate(head);
display(head);
break;

case 3:
display(head);
break;

case 4:
printf("EXITED\n");
counter++;
break;

default:
printf("WRONG CHOICE\n");
break;
}
}
 return 0; 
 } 

void insertAtRightSide(node **head,int value)
{
node *temp=(node*)malloc(sizeof(node));
temp->data=value;
if(*head==NULL)
{
temp->next=*head;
*head=temp;
}
else
{
node *temp2=*head;
while(temp2->next!=NULL)
{
    temp2=temp2->next;
}
temp2->next=temp;
temp->next=NULL;
}

}
void display(node *head)
{
node *temp;
temp=head;
printf("List is : ");
while(temp!=NULL)
{
printf(" %d ",temp->data);
temp=temp->next;
}
printf("\n");
}

void deleteAtAlternate(node* head)
{
if (head == NULL) 
        return; 

  node *temp=head->next;
  if(temp==NULL)
    return;


    head->next=temp->next;
    free(temp);
    deleteAtAlternate(head->next);   
}



//Errors reporting is most welcomed...
