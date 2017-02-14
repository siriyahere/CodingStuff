#include<stdio.h>
int dp[1001];
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
		int n,m;
		scanf("%d",&m);
		int i,j;
		int arr[m];
		for(i=0;i<m;i++)
		{
			scanf("%d",&arr[i]);
			
			dp[i]=arr[i];
		}
		for(int i=1;i<m;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(arr[i]>arr[j]&&dp[i]<dp[j]+arr[i])
					dp[i]=dp[j]+arr[i];
			}
		}
		int max=dp[0];
		for(i=1;i<m;i++)
		{
			if(max<dp[i])
				max=dp[i];	
		}	
		printf("%d\n",max);
	}
	return 0;
}
	

