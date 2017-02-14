#include<stdio.h>

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int max3(int a,int b,int c)
{
	if(a>b)
	{
		if(a>c)
			return a;
		else 
		return c;
	}
	else 
	{
	
		if(b>c)
		{		
			return b;
		}
		else
			return c;		
	}
	
}

int cutRod(int a[],int n)
{
	int i,j;
	int val[n+1]={0};
	for(i=1;i<=n;i++)
	{
		int maxi=-1;
		for(j=0;j<i;j++)
		{
			maxi=max(maxi,a[j]+val[i-j-1]);
			
		}
		val[i]=maxi;
	}
	return val[n];
}

int maxProductcut(int n)
{
	int i,j;
	int val[n+1]={0};
	for(i=1;i<=n;i++)
	{
		int maxi=-1;
		for(j=0;j<=i/2;j++)
		{
			maxi=max3(maxi,(i-j)*j,val[i-j]*j);			
		}
		val[i]=maxi;
	}
	return val[n];
}

int maxCuts(int x,int y,int z,int n)
{
	
	int maxi=0;
	int dp [4001]={0};
	dp [0]=0;
	for(int i=1;i<=n;i++)
	{
		if(i-x>=0&&dp[i-x]!=0)
		{
			maxi = max(dp[i],dp[i-x]+1);
		}
		if(i-y>=0)	
			maxi = max(dp[i-y]+1,maxi);
		if(i-z>=0)
			maxi = max(dp[i-z]+1,maxi);
		dp[i]=maxi;
	}
	return dp[n];
}

int main()
{
/*	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
    printf("%d\n",maxProductcut(10));
    printf("%d\n",maxCuts(2,1,1,4));
*/
	int tc;
//	scanf("%d",&tc);
//	while(tc--){
		int n;
		int x,y,z;
		scanf("%d",&n);
		scanf("%d%d%d",&x,&y,&z);
		printf("%d\n",maxCuts(x,y,z,n));		
//	}
	return 0;
}
