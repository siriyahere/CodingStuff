#include<stdio.h>
int a[100001];
int dp[100001];
int min(int a,int b)
{
	if(a<b)
		return a;
	else 
		return b;
}
int mini(int a,int b,int c,int d){
	
	return min(min(a,b),min(c,d));
}
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n; scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int min=mini(a[0],a[1],a[2],a[3]);
		dp[0]=dp[1]=dp[2]=dp[3]=min;
		for(int i=4;i<n;i++)
		{
			dp[i]=mini(dp[i-4],dp[i-1],dp[i-2],dp[i-3])+a[i];
		}
		printf("%d\n",dp[n-1]);
	}
}
