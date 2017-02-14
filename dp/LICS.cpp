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
		int a1[m];
		for(i=0;i<m;i++)
		{
			scanf("%d",&a1[i]);
		}
		
		int dp[n]={0};
		for(i=0;i<m;i++)
		{
			int current=0;
			for(j=0;j<n;j++)
			{
				if(a1[i]==a2[j])
				{
					if(current+1>dp[j])
						dp[j]=current+1;	
				}
				else if(a1[i]>a2[j])
				{
					if(dp[j]>current)
						current=dp[j];
				}
			}
		}
		int max=dp[0];
		for(i=1;i<n;i++)
		{
			if(max<dp[i])
				max=dp[i];
		}
		printf("%d\n",max);
	}
	return 0;
}
