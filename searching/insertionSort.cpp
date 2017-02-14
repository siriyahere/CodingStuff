 //Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted.

#include<stdio.h>
void InsertionSort(int arr[],int n)
{
	int i,j;
	int key;
	for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>0&&arr[j]>key)  //O(1) -> sorted reverse=> O(n)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
	//return 0;
}

int main()
{
	int arr[] = {1,2,4,3,7,6,4};
	InsertionSort(arr,7);
	int i;
	for(i=0;i<7;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}
