// EXP 1 (C): BUBBLE SORT
// sorting data in the correct order
//printing passes too
#include <stdio.h>
int arr[20], n, i;
void bubble(int arr[20], int n)
{
    int j, temp;
    for (i=0; i<n-1; i++)	 // passes
	{
        printf("\nPass %d: ", i+1);
        for (j=0; j<n-(i+1); j++) // comparisons
        {
            if (arr[j] > arr[j+1])
			{
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            // step wise step printing of the array after each pass
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
        scanf("%d", &arr[i]); // or (arr+i)
    }
    // Printing the original array
    printf("Original Array=");
    for (i = 0; i < n; i++) {
        printf("%d \t", arr[i]);
    }
    // Bubble sorting
    bubble(arr, n);

    return 0;
}



/*
//dont print passes
#include <stdio.h>
int arr[20], n, i;
int bubble (int arr[20], int n)
{
	int j, temp;
	for(i=0; i<n-1; i++) //passes
	{
		for(j=0; j<n-(i+1); j++)  //comparison
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
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
	// bubble sorting
	bubble (arr ,n);
	return 0;
}

*/


