/* Q3. Write a C program Create a  Dynamic array and then Reverse the array  using recursion and then finally print the array.*/
#include<stdio.h> 
#include<stdlib.h>

void Input();
void Reverse(int *,int,int);
void print(int *,int);

 int main() 
 { 
    printf("Himanshu Chauhan F 20011493\n");
    Input();
    return 0; 
 } 
 
 void Input()
 {
 int num,i=0;
 printf("Enter the size of the array : ");
 scanf("%d",&num);
int *arr=(int*)malloc(sizeof(int)*num);
 for(int i=0;i<num;i++)
 {
     printf("Enter the number %d :",(i+1));
    scanf("%d",&arr[i]);
 }

 Reverse(arr,0,num-1);
 print(arr,num);
 }

void Reverse(int *arr,int start, int end)
{
    int store;
    if(start>=end)
      return;
   store=arr[start];
   arr[start]=arr[end];
   arr[end]=store;   
   Reverse(arr,start+1,end-1);
   
}
void print(int *arr,int num)
{
   printf("Array elements after reversing are : ");
for(int i=0;i<num;i++)
 {
     printf(" %d ",arr[i]);
 }
}//Errors reporting is most welcomed...
