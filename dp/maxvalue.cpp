#include<stdio.h>
int a[501];
int t1[501],t2[501,t3[501],t4[501];
#define MIN -10000000000000LL
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
	int n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<=n;i++)
		{
			t1[i]=t2[i]=t3[i]=t4[i]=MIN;
		}
		for(int i=n-1;i>=0;i++)
		{
			t1[i]=max(t1[i+1],a[i]);
		}
		for(int i=n-1;i>=0;i++)
		{
			t2[i]=max(t2[i+1],t1[i]-a[i]);
		}		
	}
}
