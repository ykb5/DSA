/*Q2. Write a the C program to create an array by inserting  N elements in it then find third repeating element from the array.*/
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
    if(a[j]!=-1&&i!=j)
    {
    if(a[i]==a[j]&&i!=j)
    {
        c++;
        a[j]=-1;
    }
    }
    }
        if(c>0)
            d++;

        if(d==3)
        {
            break;
        }
    }

    if(d==3)
        printf("\nThird repeating element is %d",a[i]);
    else
        printf("\nThird repeating element not found");

    return 0;
        
}


//Errors reporting is most welcomed...
