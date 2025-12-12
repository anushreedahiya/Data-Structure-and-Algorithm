// EXP 1 (B): BINARY SEARCH
//binary search with iteration
#include <stdio.h>
int arr[20], i, n, flag=0;

void search_binary()
{
	int a, mid, beg, end;
	printf("Enter the number to search in the array=");
	scanf("%d",&a);
	beg=0;
	end=n-1;
	while (beg<=end)
	{
		mid=(beg+end)/2;
		printf("\n Beginning index value of the array=%d",beg);
		printf("\n Middle index value of the array=%d",mid);
		printf("\n End index value of the array=%d",end);
		printf("\n --------------");
		printf("\n Beginning value of the array=%d",arr[beg]);
		printf("\n Middle value of the array=%d",arr[mid]);
		printf("\n End value of the array=%d",arr[end]);
		printf("\n --------------");
		if (arr[mid]==a)   //case 1
		{
			printf("\n Element found at position=%d in the array",mid+1);
			flag=1;
			return;
		}
		else if (arr[mid]<a)    //case 2
		{
			beg=mid+1;
		}
		else if (arr[mid]>a)    //case 3
		{
			end=mid-1;
		}
	}
	if (flag==0)
	{
		printf("Element not found");
	}
}

// main code
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
		printf("%d \n",arr[i]);
	}
	// binary search
	search_binary();
	return 0;
}


