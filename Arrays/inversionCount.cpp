#include<stdio.h>

int merge(int arr[],int l,int m,int r)
{
	int n1=(m-l)+1; //l=1  r=4 m=2 n1=1  1 2 3 4  1
	int n2=(r-m); //n2= 3
	int i,j,k;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	{
		L[i]=arr[l+i]; //L ->1
	}
	for(i=0;i<n2;i++) //n2 = 3 i=0,1,2 m+i 2,3,4   //1464
	{
		R[i]=arr[m+i+1]; //R - 464
	}
	k=l;
	i=j=0;
	int count=0;
	while(i<n1&&j<n2)
	{
		if(L[i]<R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
			count+=(n1-i);
		}
		k++;
	}
	while(i<n1)
	{
		arr[k++]=L[i++];
	}
	while(j<n2)
	{
		arr[k++]=R[j++];
	//	count++;
	//	count++;
	}
	return count;
}

int mergeSort(int arr[],int l,int r)
{
	int count =0;
	if(l<r)
	{
		int mid=(l+r)/2;
		count=mergeSort(arr,l,mid);
		count+=mergeSort(arr,mid+1,r);
		count+=merge(arr,l,mid,r);
	}
	return count;
}

int main()
{
	int tc;
	int count=0;
	scanf("%d",&tc);
	int n,i;
	while(tc--)
	{
		count=0;
		scanf("%d",&n);
		int arr[n] ;
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		count= mergeSort(arr,0,n-1);
		
		printf("%d\n",count);
	}
	return 0;
}
