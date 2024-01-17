#include <stdio.h>
int recursiveBinarySearch(int arr[], int start_index, int end_index, int key)
{
    if (end_index >= start_index)
    {
        int middle = start_index + (end_index - start_index) / 2;
        if (arr[middle] == key)
            return middle;
        if (arr[middle] > key)
            return recursiveBinarySearch(arr, start_index, middle - 1, key);
        return recursiveBinarySearch(arr, middle + 1, end_index, key);
    }
    return -1;
}
int main()
{
    int n, key, count;
    printf("Gaurab Singh _F_20011391\n");
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nEnter the key to find: ");
    scanf("%d", &key);
    count = recursiveBinarySearch(arr, 0, n - 1, key);
    if (count == -1)
    {
        printf("\nNot found.");
    }
    else
    {
        printf("\nElement found. And the count is: %d\n", count);
    }
    return 0;
}