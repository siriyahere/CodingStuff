#include<stdio.h>

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n,i,j;
		scanf("%d",&n);
		int a[2][n];
		int sum[n];
		
		sum[0]=0;
		
		for(j=0;j<=1;j++)
			for(i=0;i<n;i++)
				scanf("%d",&a[j][i]);
		for( i=0;i<n;i++)
		{
			
			int ele=max(a[0][i],a[1][i]);
			int max=0;
			for(j=i-2;j>=0;j--)
			{
				if(sum[j]>max)
					max=sum[j];	
			}
			sum[i]=max+ele;
		}
			int max=sum[0];
			for( i=1;i<n;i++)
			{
				if(max<sum[i])
					max=sum[i];
			}
		printf("%d\n",max);
	}
}
