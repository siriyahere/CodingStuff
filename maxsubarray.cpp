
//kadane algorithm
#include<stdio.h>

int a[10010];
//int dp[100010][100010];
//O(n) algorithm
long long maxsub(int n)
{
	long long max_sofar=a[0];
	long long max_ifend=a[0];
	for(int i=1;i<n;i++)
	{
		max_ifend=a[i]+max_ifend;
	//	if(max_ifend<0)  -> onlu +ve cases
		if(max_ifend<a[i])   //for all -ve numbers also
			max_ifend=a[i];
		if(max_ifend>max_sofar)
			max_sofar=max_ifend;
	}
	return max_sofar;
}


long long sum(int n)
{
	for(int i=1;i<n;i++)
	{
		int key=a[i];
		int j=i-1;
		while(j>=0&&a[j]<=key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
		
	}
	
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<=0)
			break;
		sum+=a[i];
	}
	return sum;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("%lld ",maxsub(n));
		printf("%lld\n",sum(n));
	}
	return 0;
}
