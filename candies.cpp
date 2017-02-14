#include<stdio.h>
long long dp[100010];
long a[100010];
int main()
{
	long tc;
	scanf("%ld",&tc);
	long long c=0;
	for(unsigned int i=0;i<tc;i++)
	{
		scanf("%ld",&a[i]);
		dp[i]=1;
	}
	
	for(unsigned int i=1;i<tc;i++)
	{
		if(a[i]>a[i-1])	
		{
			dp[i]=dp[i-1]+1;
		}
	}
	for(unsigned int i=tc-2;i>=0;i--)
	{
		if(a[i]>a[i+1])
			if(dp[i]<=dp[i+1])
				dp[i]=dp[i+1]+1;
		if(i==0)
			break;
	}
/*	for(int i=0;i<tc;i++)
		printf("%d ",a[i]);
	printf("\n");
*/	for(unsigned int i=0;i<tc;i++)
	{
//		printf("%d ",dp[i]);
		c+=dp[i];
	}
	printf("%lld\n",c);
}
