#include<stdio.h>
int main()
{
	int a[10]={-7,-4,-3,0,1,3,4,6,8,9};
	int n=10;
	int i=0,j=n-1;
	int count=n;
	while(i<j)
	{
		
		while(i<j&&a[i]==a[i+1])
		{
			count--;
			i++;
		}
		while(j>i&&a[j]==a[j-1])
		{
			count--;
			j--;
		}
		int sum=a[i]+a[j];
		
		if(sum>0)
		{
			j--;
			
		}
		else if(sum<0)
		{
			i++;	
		//	count++;
		}
		else
		{
			count=count-1;
			i++;
			j--;
		}
	}
	printf("%d\n",count);
}
