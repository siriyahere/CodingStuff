/*
Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
Auxiliary Space: O(1)
Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
Sorting In Place: Yes
Stable: Yes
*/


#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void BubbleSort(int arr[],int n)
{
	int i,j;
	bool swapped=true;
	for(i=0;i<n-1;i++)
	{
		swapped=false;
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j+1]<arr[j])
			{
				swap(&arr[j],&arr[j+1]);
				swapped=true;
			}
			
		}
		if(!swapped)
				break;
	}
}

int main()
{
	int arr[] = {1,2,4,3,7,6,4};
	BubbleSort(arr,7);
	int i;
	for(i=0;i<7;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}
