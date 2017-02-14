#include<stdio.h>
int dp[1001][1001];
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

//O(n^2)
int lcs(char *x,char *y,int m,int n)
{
//	int m=strlen(x);
//	int y=strlen(y);
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(x[i-1]==y[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j] =max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[m][n];
	
}

int main()
{
	int tc;
	scanf("%d",&tc);
	
	while(tc--){
		int m,n;
		char x[101]	;
		char y[101];
		scanf("%d%d",&m,&n);
		scanf("%s%s",x,y);
		printf("%d\n",lcs(x,y,m,n));
	}
	
	
}
