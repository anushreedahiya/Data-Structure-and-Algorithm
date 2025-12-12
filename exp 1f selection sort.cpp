// EXP 1 (E): SELECTION SORT
// sorting data in the correct order
#include <stdio.h>
int arr[20], n, i;

void selection(int arr[20], int n)
{
    int j, temp, min, position;
    for (i=0; i<n-1; i++) //4 passes if n=5
	{	//i=0,1,2,3
        min=i;	//min=0,1,2,3
        printf("\nPass %d: ", i + 1);
        for (j=i+1; j<n; j++)	//comparisons
		{
            if (arr[min] > arr[j])
			{
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        // Print the array after each pass
        for (int k=0; k<n; k++)
		{
            printf("%d \t", arr[k]);
        }
        printf("\n");
    }
}

int main()
{
    // Taking input of the array
    printf("Enter the total number of elements that you want in the array=");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
	{
        printf("Enter the element for the array=");
        scanf("%d", &arr[i]);
    }
    // Printing the original array
    printf("Original Array=");
    for (i = 0; i < n; i++)
	{
        printf("%d \t", arr[i]);
    }
    // Selection sorting
    selection(arr, n);
    return 0;
}




/*
//dont print passes
#include <stdio.h>
int arr[20], n, i;
int selection(int arr[20], int n)
{
	int j, k, temp, min, position;
	for(i=0; i<n-1; i++) //4 passes if n=5
	{	//i=0,1,2,3
		min=i;	//min=0,1,2,3
		for(j=i+1; j<n; j++)	//comparisons
		{
			if(arr[min]>arr[j])
			{
				min=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
	printf("\nSorted Array=");
	for (i=0; i<n; i++)
	{
		printf("%d \t",arr[i]);
	}
}

int main()
{
	//taking input of the array
	printf("Enter the total number of elements that you want in the array=");
	scanf("%d",&n);
	for (i=0; i<n; i++)
	{
		printf("Enter the element for the array=");
		scanf("%d",&arr[i]);    // or (arr+i)
	}
	//printing the array
	printf("Array=");
	for (i=0; i<n; i++)
	{
		printf("%d \t",arr[i]);
	}
	// selection sorting
	selection (arr ,n);
	return 0;
}

*/
