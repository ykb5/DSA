/*Q10. Write a C Program implement QUEUE using array in menu driven form.*/
#include<stdio.h>
#define size 5

void Enqueue(int*,int*,int*);
void Dequeue(int*,int*,int*);
void Display(int*,int*,int*);



int main()
{
printf("Himanshu Chauhan F 20011493\n");
int queue[size],front=-1,rear=-1;
int counter=0,choice;
while(counter==0)
{
printf("1.INSERT  \n2.DELETE \n3.DISPLAY \n4.EXIT \n");
scanf("%d",&choice);

switch(choice)
{
case 1:
Enqueue(queue,&front,&rear);
break;

case 2:
Dequeue(queue,&front,&rear);
break;

case 3:
Display(queue,&front,&rear);
break;

case 4:
printf("EXITED \n");
counter++;
break;

default:
printf("WRONG CHOICE \n");
break;
}
}
return 0;
}

void Enqueue(int queue[],int *front ,int *rear)
{
int value;
if(*rear==size-1)
{
printf("Queue is Full\n");
}
else
{
printf("Enter a value\n");
scanf("%d",&value);
if(*front==-1)
{
*front=*front+1;
}
*rear=*rear+1;
queue[*rear]=value;
printf("Entered %d SUCCESSFULLY \n",value);
}
}

void Dequeue(int queue[],int *front,int *rear)
{
if(*front==-1)
{
printf("Queue is Empty\n");
}
else
{
printf("Deleted %d Successfully\n",queue[*front]);
*front=*front+1;
if(*front>*rear)
{
*front=*rear=-1;
}
}
}

void Display(int queue[],int *front,int *rear)
{
if(*front==-1)
{
printf("Queue is Empty\n");
}
else
{
for(int i=*front;i<=*rear;i++)
{
printf("%d ",queue[i]);
}
printf("\n");
}
}




//Errors reporting is most welcomed...
