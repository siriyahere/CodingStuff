#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int p,int q);
void quicksort(int a[],int p,int q)
{
	if(p<q)
	{
		int r=partition(a,p,q);
		quicksort(a,p,r-1);
		quicksort(a,r+1,q);
	}
}

int partition(int a[],int p,int q)
{
	int key=a[q];
	int pos=p-1;
	int i;
	for(i=p;i<q;i++)
	{
		if(a[i]<key)
		{
			pos=pos+1;
			swap(&a[i],&a[pos]);
		}	
	}
	swap(&a[pos+1],&a[q]);
	return pos+1;
}

int main()
{
	int arr[] = {1,2,4,7,6,4};
	quicksort(arr,0,5);
	int i;
	for(i=0;i<6;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}



