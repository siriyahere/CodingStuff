#include<stdio.h>
int dp[1000010];
int a[1000010];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		dp[i]=a[i];
		
	}
	int max=0;
	//int sum=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j]<=a[i]&&dp[i]<dp[j]+a[i])
			{
					dp[i]=dp[j]+a[i];
				//	sum+=a[j];
				//	sum+=a[j];
			}
				
		}
		if(max<dp[i])
		{
				max=dp[i];
				
		}
	}
	
	int sum=0;
/*	for(int i=0;i<n;i++)
	{
		printf("\n%d",dp[i]);
	}*/
	for(int i=0;i<n;i++){
	
		if(dp[i]==(dp[i+1]-1))
			sum+=a[i];
	}
	if(dp[n-2]!=dp[n-1])
		sum=sum+a[n-1];
	printf("%d\n",max);
	return 0;
	
	
}
