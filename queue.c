#include <stdio.h>
#define MAX 10

void enqueue(int q[], int n, int *front, int *rear)
{
	if (*front == (*rear + 1) % MAX)
	{
		printf("\nThe Queue is full.\n");
		return;
	}
	if (*front == -1)
	{
		*front = 0;
		*rear = 0;
		q[*rear] = n;
	}
	else
	{
		*rear = (*rear + 1) % MAX;
		q[*rear] = n;
	}
}
int dequeue(int q[], int *front, int *rear)
{
	if (*front == -1)
	{
		printf("\nThe Queue is Empty.\n");
		return -1;
	}
	int temp;
	if (*rear == *front)
	{
		temp = q[*front];
		*rear = -1;
		*front = -1;
	}
	else
	{
		temp = q[*front];
		*front = (*front + 1) % MAX;
	}
	return temp;
}
void display(int q[], int *front, int *rear)
{
	int temp = *front;
	if (*front == -1)
	{
		printf("\nThe Queue is Empty.\n");
		return;
	}
	printf("\nThe Queue elements are: \n");
	while (temp != *rear)
	{
		printf("%d ", q[temp]);
		temp = (temp + 1) % MAX;
	}
	printf("%d\n", q[temp]);
}

int main()
{
	int q[MAX], n;
	int front = -1, rear = -1;
	int choice;
	int temp;
	do
	{
		printf("Enter the Choice: \n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\nEnter the Number to enqueue: ");
			scanf("%d", &n);
			enqueue(q, n, &front, &rear);
			break;
		case 2:
			temp = dequeue(q, &front, &rear);
			if (temp != -1)
				printf("\nThe dequeued element is: %d\n", temp);
			break;
		case 3:
			display(q, &front, &rear);
			break;
		case 0:
			return 0;
		default:
			printf("\nThe input is Invalid.\n");
		}
	} while (choice != 0);

	return 0;
}

//@BKY