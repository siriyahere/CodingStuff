#include<stdio.h>

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int kadane(int * a,int n)
{
	int max_so_far=a[0];
	int max_end =a[0];
	for(int i=1;i<n;i++)
	{
	//	printf("%d",a[i]);
		
		max_end=max(a[i],max_end+a[i]);
		max_so_far = max(max_end,max_so_far);
	}
	return max_so_far;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	
	while(tc--)
	{
		int a[10];
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("%d ",kadane(a,n));
	//	printf("%lld\n",sum(n));
	}
	return 0;
}
