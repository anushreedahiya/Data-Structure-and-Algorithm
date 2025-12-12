// EXP 1 (D): INSERTION SORT
// sorting data in the correct order
//Printing passes too
#include <stdio.h>
int arr[20], n, i;

void insertionSort(int arr[20], int n)
{
    int j, temp;
	for(i=0; i<n; i++)
	{
		j=i;
		while(j<=i && j>0)
		{
			if(arr[j]<arr[j-1])
			{
				temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
			j--;
			printf("\nPass %d: ", i);
        	for (int k = 0; k < n; k++)
			{
        	    printf("%d \t", arr[k]);
        	}
        	printf("\n");
		}
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
    // Insertion sorting
    insertionSort(arr, n);

    return 0;
}



/*
//dont print passes
#include <stdio.h>
int arr[20], n, i;
int insertion (int arr[20], int n)
{
	int j, temp;
	for(i=0; i<n; i++)
	{
		j=i;
		while(j<=i && j>0)
		{
			if(arr[j]<arr[j-1])
			{
				temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
			j--;
		}
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
	// insertion sorting
	insertion (arr ,n);
	return 0;
}
*/

