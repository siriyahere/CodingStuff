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
	int W;
	int wt[100];
	int val[100];
	int dp[101][101];
	int tc;
	int n;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&n);
		scanf("%d",&W);
		int i,w;
		for(i=0;i<n;i++)
		{
			scanf("%d",&val[i]);
			scanf("%d",&wt[i]);
		}
		for( i=0;i<=n;i++)
		{
			for(w=0;w<=W;w++)
			{
					if(i==0||w==0)
						dp[i][w]=0;
					else if(wt[i-1]<=W)
					{
						dp[i][w]=max(val[i-1]+dp[i][W-wt[w-1]],dp[i-1][w]);
					}
					else
						dp[i][w]=dp[i-1][w];
			}
		}
		printf("%d\n",dp[n][W]);
	}
	return 0;
}
