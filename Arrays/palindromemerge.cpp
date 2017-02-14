#include<stdio.h>
int a[100];
int main()
{
	int tc;
	scanf("%d",&tc);
	int n;
	while(tc--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int i=0;
		int j=n-1;
		int count =0;
		while(i<j)
		{
			if(a[i]==a[j])
			{
				i++;
				j--;
			}
			else if(a[i]>a[j])
			{
				a[j-1]=a[j]+a[j-1];
				j--;
				count++;
			}
			else
			{
				a[i+1]=a[i]+a[i+1];
				i++;
				count++;
			}
		}
		printf("%d\n",count);
	}
}
