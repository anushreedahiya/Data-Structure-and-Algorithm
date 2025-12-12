//displaying an array using function
//linear search
#include<stdio.h>
int arr[20], i, n, flag=0;
void myarray()
{
	printf("array=");
	for (i=0; i<n; i++)
	{
		printf("%d \n",arr[i]);
	}
}

void input_array()
{
	printf("enter the total number of elements that you want in the array=");
	scanf("%d",&n);
	for (i=0; i<n; i++)
	{
		printf("enter the element for the array=");
		scanf("%d",&arr[i]);    // or (arr+i)
	}
}

void search_arr()
{
	int a;
	printf("enter the number to search in the array=");
	scanf("%d",&a);
	for (i=0; i<n; i++)
	{
		if (a==arr[i])
		{
			flag=1;
		}
	}
}

// main code
int main()
{
	input_array();
	myarray();
	search_arr();
	if (flag==0)
	{
		printf("element not found");
	}
	else
	{
		printf("element found");
	}
	return 0;
}


