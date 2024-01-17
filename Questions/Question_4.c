/*Q4. Write a C Program implement STACK using array in menu driven form.*/
#include<stdio.h>
#include<stdlib.h>
#define size 5


int Insert(int *arr,int top)
{
if(top==size-1)
{
printf("STACK IS FULL \n");
}
else
{
int num;
printf("Enter the value: \n");
scanf("%d",&num);
top++;
arr=(int *)realloc(arr,sizeof(int)*(top+1));
arr[top]=num;


printf("ADDED %d SUCCESSFULLY\n",arr[top]);

return top;
}
}
int Delete(int *arr,int top)
{
if(top==-1)
{
printf("STACK IS EMPTY\n");
}
else{

printf("DELETED %d SUCCESSFULLY\n",arr[top]);

top--;
arr=(int *)realloc(arr,sizeof(int)*(top+1));
return top;

}
}

 void Display(int *arr,int top)
{
if(top==-1)
{
printf("STACK IS EMPTY\n");
}
else
{
printf("Stack is \n");
for(int i=top;i>=0;i--)
{
printf("----------\n");
printf("|   %d   |\n",arr[i]);
printf("----------\n");
}

}
}



int main()
{

    printf("Himanshu Chauhan F 20011493\n");
int *stack,top=-1,counter=0,choice;

stack=(int*)malloc(sizeof(int )*(top+1));

while(counter==0)
{

printf("1.INSERT  \n2.DELETE \n3.DISPLAY \n4.EXIT \n");
scanf("%d",&choice);

switch(choice)
{
case 1:
top=Insert(stack,top);
break;

case 2:
top=Delete(stack,top);
break;

case 3:
Display(stack,top);
break;

case 4:
printf("EXITED \n");
counter++;
break;

default:
printf("WRONG CHOICE \n");
}
}


return 0;
}//Errors reporting is most welcomed...
