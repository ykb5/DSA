/* Q1. Write a the C program to create an array by inserting  N elements in it then find second non repeating element from the array.*/
#include<stdio.h>
int main()
{
    printf("Himanshu Chauhan F 20011493\n");
    int n,i,j,c,d=0;
    printf("Enter the limit of array: ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
    c=0;
    for(j=0;j<n;j++)
    {
    if(a[i]!=-1)
    {
    if(a[i]==a[j])
        c++;
    }
    }
        if(c==1)
            d++;

        if(d==2)
        {
            printf("\nSecond non-repeating element is %d",a[i]);
            break;
        }
    }
    return 0;
        
}


//Errors reporting is most welcomed...
