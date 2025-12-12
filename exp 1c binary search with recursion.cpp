// EXP 1 (B): BINARY SEARCH
//binary search with recursion
#include <stdio.h>
int n, i, arr[20], flag=0;
// A recursive binary search function. It returns location of x in given array arr[l..r] is present, otherwise -1
int binarysearch(int arr[], int beg, int end, int m)
{
	while (beg<=end)
	{
		int mid=(beg+end)/2;
		if (arr[mid]==m)
		{
			return mid;
		}
		else if (arr[mid]>m)
		{
			return binarysearch(arr, beg, mid-1, m);
		}
		else
		{
			return binarysearch(arr, mid+1, end, m);
		}

	}
	return -1;
}

int main()
{
	int m;
	//taking input of the array
	printf("Enter the total number of elements=");
	scanf("%d",&n);
	for (i=0; i<n; i++)
	{
		printf("enter the element for the array=");
		scanf("%d",&arr[i]);    // or (arr+i)
	}
	//printing the array
	printf("Array=");
	for (i=0; i<n; i++)
	{
		printf("%d \n",arr[i]);
	}
	// binary search
	printf("Enter the number to search in the array=");
	scanf("%d",&m);
	int result=binarysearch(arr , 0, n-1, m);
	if(result==-1)
	{
		printf("\nSorry! Element not found");
	}
	else
	{
		printf("\nElement present at position=%d",result+1);
	}
	return 0;
}


