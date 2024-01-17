/*Q8. Write a C Program implement QUEUE using Link List  in menu driven form.*rear=*rear+1;*/
#include<stdio.h> 
#include<stdlib.h>
#define max 5
struct Node
{
    int data;
    struct Node *next;

};
typedef struct Node node;

void insert(node **,int*,int*,int);
void delete(node**,int*,int*);
void display(node *top);
 int main() 
 {

 printf("Himanshu Chauhan F 20011493\n");
 node *top;
int counter=0,choice,value,pos,front=-1,rear=-1;

top=NULL;
while(counter==0)
{

printf("1.INSERT  \n2.DELETE  \n3.DISPLAY \n4.EXIT\n");
scanf("%d",&choice);

switch(choice)
{
case 1:
if(rear==max-1)
{
printf("Queue is Full\n");
}
else{
printf("Enter a value : ");
scanf("%d",&value);
insert(&top,&front,&rear,value);
}
break;

case 2:
if(front==-1)
{
printf("Queue is Empty\n");
}
else{
delete(&top,&front,&rear);
}
break;

case 3:
display(top);
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

void insert(node **top,int* front,int* rear,int value )
{
if(*front==-1)
    *front=*front+1;

node *temp=(node*)malloc(sizeof(node));
temp->data=value;
if(*top==NULL)
{
temp->next=*top;
*top=temp;
}
else
{
node *temp2=*top;
while(temp2->next!=NULL)
{
    temp2=temp2->next;
}
temp2->next=temp;
temp->next=NULL;
}
*rear=*rear+1;
}

void display(node *top)
{
node *temp;
temp=top;
printf("List is : ");
while(temp!=NULL)
{
printf(" %d ",temp->data);
temp=temp->next;
}
printf("\n");
}

void delete(node**top,int* front,int* rear)
{
if (top == NULL) 
        return; 

*front=*front+1;
node *temp=*top;
printf("%d Deleted Successfully\n",temp->data);
*top=temp->next;
free(temp);
if(*front>*rear)
    *front=*rear=-1;
}



//Errors reporting is most welcomed...
