#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};
int main()
{
    struct node *start, *end, *temp, *disp;
    int choice, count;
    //int *temp;
    start=NULL;
    do
    {
        printf("\nEnter your choice:\n1. Insert\n2. Delete\n3. Display\n4. Count\n0. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                end=(struct node*)malloc(sizeof(struct node));
                end->next=NULL;
                if(start==NULL)
                {
                    temp=start=end;
                    printf("\nEnter the element to insert: ");
                    scanf("%d", &end->value);
                }
                else
                {
                    printf("\nEnter the element to insert: ");
                    scanf("%d", &end->value);
                    temp->next=end;
                    temp=end;
                }
                break;
            case 2:
                if(start==NULL)
                    printf("\nThe list is empty.");
                else
                {
                    
                    printf("\nCan't perform this operation yet!");
                }
                break;
            case 3:
                disp=start;
                printf("\nElements in the list: ");
                while(disp!=0)
                {
                    printf("%d ", disp->value);
                    disp=disp->next;
                }
                break;
            case 4:
                count=0;
                disp=start;
                while(disp!=0)
                {
                    count++;
                    disp=disp->next;
                }
                printf("\nTotal elements in the list: %d", count);
                break;
            case 0:
                return 0;
            default:
                printf("\nInvalid choice!");
        }
    } while (choice!=0);
    
}

//@BKY