#include<stdio.h>
int a[50001];
int main()
{
	int tc;
	scanf("%d",&tc);
	for(int i=0;i<tc;i++)
	{
		int n;
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		long long max_so_far=0;
		long long profit=0;
		for(int k=n-1;k>=0;k--){
			
			if(max_so_far<a[k])
				max_so_far=a[k];
			profit+=max_so_far-a[k];
		}
		printf("%lld",profit);
	}
}
