// EXP 1 (A): LINEAR SEARCH
//linear search with multiple occurances
#include <stdio.h>
int arr[20], i, n, count=0, a;
void myarray()  //printing the array
{
	printf("array=");
	for (i=0; i<n; i++)
	{
		printf("%d \n",arr[i]);
	}
}

void input_array()  //taking input from the user
{
	printf("Enter the total number of elements that you want in the array=");
	scanf("%d",&n);
	for (i=0; i<n; i++)
	{
		printf("Enter the element for the array=");
		scanf("%d",&arr[i]);    // or (arr+i)
	}
}

void search_arr()  // searching the element in the array
{
	printf("Enter the number to search in the array=");
	scanf("%d",&a);
	for (i=0; i<n; i++)
	{
		if (arr[i]==a)    
		{
			printf("%d is present at location %d.\n", a, i+1);
			count++;
    	}
	}
}

// main code
int main()
{
	input_array();
	myarray();
	search_arr();
	if (count==0)
	{
		printf("%d is not present in array.\n", a);
	}
	else
	{
		printf("%d is present %d times in array.\n", a, count);
	}
	return 0;
}


