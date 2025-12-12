//EXP 1 (F): MERGE SORT
// C program for Merge Sort
// First subarray is arr[l..m] and second subarray is arr[m+1..r]
#include <stdio.h>
int d=1, n;

void printArray(int arr[], int size)  // printing the array
{
    int i;
    for (i = 0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
	int n1=m-l+1;
	int n2=r-m;
    int L[n1], R[n2];    // Create temp arrays
    for (i=0; i<n1; i++)    // Copy data to temp arrays
    {
        L[i]=arr[l+i];
	}
	for (j=0; j<n2; j++)
    {
	    R[j]=arr[m+1+j];
	}
    // Merge the temp arrays back into arr[l..r]
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    k = l;    // Initial index of merged subarray
    while (i < n1 && j < n2)
	{
        if (L[i] <= R[j]) 
		{
            arr[k] = L[i];
            i++;
        }
        else
		{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)    // Copy the remaining elements of L[], if there are any
	{
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)    // Copy the remaining elements of R[], if there are any
	{
        arr[k] = R[j];
        j++;
        k++;
    }
    printf("\n passes=%d\n ",d);
    d++;
	printArray(arr, r);
}

void mergeSort(int arr[], int l, int r)
{
    if (l<r)
	{
        int m=l+(r-l)/2;   //m=middle value; l=left; r=right
		// Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);    // dividing the array as much as possible as the final array has only 1 element
		merge(arr, l, m, r);
    }
}

int main()
{
    int i, arr[20];
    printf("Enter the size of array=");
    scanf("%d",&n);
    printf("Enter the elements of first array=");
    for(i=0; i<n; i++)
	{      
       scanf("%d", &arr[i]);
	}
    printf("Given array is \n");
    printArray(arr, n);
  
    mergeSort(arr, 0, n-1);
  
    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}


