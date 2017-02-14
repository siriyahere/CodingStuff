#include<stdio.h>
long long dp[251][251];
long long sum(int *a,int m,int n)
{
	for(int i=0;i<=m;i++)
	{
		
		//give back 0 cents using all coins
		dp[0][i]=1;
		
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=0;
		for(int j=1;j<=m;j++){
		
		//give back i cents
		long long temp=dp[i][j-1];
		if(a[j-1]<=i)
			temp+=dp[i-a[j-1]][j];
			
		dp[i][j]=temp;
		}
	}
	return dp[n][m]	;
	
}

int main()
{
	int n;
	int m;
	int a[50];
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		
	}
	printf("%lld",sum(a,m,n));
	
}
