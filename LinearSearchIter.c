//Linear Search iterative approach
#include <stdio.h>
int lineariterapp(int arr[], int n, int key, int count)
{
	for(int i=0; i<n; i++)
	{
		count++;
		if(arr[i]==key)
			return count+1;
	}
	return -1;
}
int main()
{
	int n, key, count=-1;
	printf("ShivaliRawat_F_20012243\n");
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	
	printf("\nEnter the key to find: ");
	scanf("%d", &key);
	count = lineariterapp(arr, n, key, count);
	if(count==-1)
		printf("\nNot Found.\n");
	else
		printf("\nElement found. And the count is: %d\n", count);
	
	return 0;
}