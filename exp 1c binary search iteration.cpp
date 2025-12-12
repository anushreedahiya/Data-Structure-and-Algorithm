//displaying an array using function
//binary search
#include <stdio.h>
int arr[20], i, n, flag=0;

void search_binary()
{
	int a;
	int mid, beg, end;
	printf("enter the number to search in the array=");
	scanf("%d",&a);
	beg=0;
	end=n-1;
	while (beg<=end)
	{
		mid=(beg+end)/2;
		printf("\n beginning index value of the array=%d",beg);
		printf("\n middle index value of the array=%d",mid);
		printf("\n end index value of the array=%d",end);
		printf("\n --------------");
		printf("\n beginning value of the array=%d",arr[beg]);
		printf("\n middle value of the array=%d",arr[mid]);
		printf("\n end value of the array=%d",arr[end]);
		printf("\n --------------");
		if (arr[mid]==a)   //case 1
		{
			printf("\n element found at position=%d",mid+1);
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
		printf("element not found");
	}
}

// main code
int main()
{
	//taking input of the array
	printf("enter the total number of elements that you want in the array=");
	scanf("%d",&n);
	for (i=0; i<n; i++)
	{
		printf("enter the element for the array=");
		scanf("%d",&arr[i]);    // or (arr+i)
	}
	//printing the array
	printf("array=");
	for (i=0; i<n; i++)
	{
		printf("%d \n",arr[i]);
	}
	// binary search
	search_binary();
	return 0;
}


