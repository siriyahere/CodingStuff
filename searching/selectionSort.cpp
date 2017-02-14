/*
The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.
*/


#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void SelectionSort(int arr[],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[min]>arr[j])
				min=j;
		}
		swap(&arr[i],&arr[min]);
	
	}
}
int main()
{
	int arr[] = {1,2,4,3,7,6,4};
	SelectionSort(arr,7);
	int i;
	for(i=0;i<7;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}
