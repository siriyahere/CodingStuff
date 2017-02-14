#include<stdio.h>

static int R=100;
static int C=100;
int dp[100][100];

int min(int a,int b,int c)
{
	if(a<b)
	{
		if(a<c)
			return a;
		else
			return c;
	}
	else
	{
		if(b<c)
			return b;
		else
			return c;
	}
}

int minCost(int cost[3][3],int r,int c)
{
	
	dp[0][0]=cost[0][0];
	for(int i=1;i<=c;i++)
		dp[0][i]=dp[0][i-1]+cost[0][i];
	for(int i=1;i<=r;i++)
		dp[i][0]=dp[i-1][0]+cost[i][0];
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			dp[i][j]=min(dp[i-1][j],dp[i-1][j+1],dp[i][j-1])+cost[i][j];
		
	
	return dp[r][c];
}



int main()
{
   int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   printf(" %d ", minCost(cost, 2, 2));
   return 0;
}
