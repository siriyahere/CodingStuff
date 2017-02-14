#include<stdio.h>
#include<string.h>
int dp[101][101];

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
int edit(char s[100],char t[100],int m,int n)
{
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=i;
			else if(s[i-1]!=s[j-1])
			{
				dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
			}
			else
				dp[i][j]=dp[i-1][j-1];
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
		char a[100];
		char b[100];
		scanf("%d%d",&m,&n);
		scanf("%s%s",a,b);
		//int m=strlen(a);
		//int n=strlen(b);
		printf("%d\n",edit(a,b,m,n));
		
	}
	return 0;
}
