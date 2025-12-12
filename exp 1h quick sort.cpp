//EXP 1 (G): QUICK SORT
// C program for Quick Sort
// First subarray is arr[l..m] and second subarray is arr[m+1..r]
#include <stdio.h>
void swap(int *a, int *b)
{
	int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
	int pivot, i, j;
    pivot=arr[high];
    i=(low-1);
    for (j=low; j<=high-1; j++)
	{   
        if (arr[j]<=pivot)
		{
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high)
{
    if (low<high)
	{
        int pivotIdx = partition(arr, low, high);
        // Print the array at each pass
        printf("Pass: ");
        for (int k = low; k <= high; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");

        quickSort(arr, low, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, high);
    }
}

int main()
{
    int n, arr[20], i;
    printf("Enter the number of elements=\n ");
    scanf("%d", &n);
    printf("Enter the elements=\n");
    for (i=0; i<n; i++)
	{
        scanf("%d", &arr[i]);
    }
    printf("Original array=\n");
    for (i=0; i<n; i++)
	{
        printf("%d ", arr[i]);
    }
    quickSort(arr, 0, n-1);
    printf("\nSorted array=\n ");
    for (i=0; i<n; i++)
	{
        printf("%d ", arr[i]);
    }
    return 0;
}


