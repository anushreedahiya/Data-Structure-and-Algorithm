// EXP 1 (B): BINARY SEARCH
//binary search with recursion
#include <stdio.h>
int n, i, arr[20], flag=0;
// A recursive binary search function. It returns location of x in given array arr[l..r] is present, otherwise -1
int binarysearch(int arr[], int beg, int end, int m)
{
	if(beg<=end)
	{
		int mid=(beg+end)/2;
		if(arr[mid]==m)
		{
			return mid;
		}
		if(arr[mid]>m)
		{
			return binarysearch(arr, beg, mid-1, m);
		}
		return binarysearch(arr, mid+1, end, m);
	}
	return -1;
}

int main()
{
	int m;
	//taking input of the array
	printf("Enter the total number of elements that you want in the array=");
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


/*
int binarySearch(int arr[], int l, int r, int x)
{
    if (r>=l)  // r=end and l=starting point
	{
        int mid=l+(r-l)/2;
        // If the element is present at the middle itself
        if (arr[mid]==x)
            return mid;
        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid]>x)
            return binarySearch(arr, l, mid-1, x);
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
    }
    // We reach here when element is not present in array
    return -1;
}
 
// Driver code
int main()
{
	int n, i, arr[20];
	printf("enter the total number of elements that you want in the array=");
	scanf("%d",&n);
	for (i=0; i<n; i++)
	{
		printf("enter the element for the array=");
		scanf("%d",&arr[i]);    // or (arr+i)
	}
    int result=binarySearch(arr, 0, n-1, i);
    (result== -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    return 0;
}

*/

