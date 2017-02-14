#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int tc;
	scanf("%d",&tc);
	int n;
	
	while(tc--)
	{
		scanf("%d",&n);
		int a[n];
		int cnt=n;
		int i=0,j=n-1;
		memset(a,0,sizeof(int)*n);

		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		i=0;
		while(i<j)
		{
			while(i<j&&a[i]==a[i+1])
			{
				cnt--;
				i++;
			}
			while(i<j&&(a[j]==a[j-1]))
			{
				cnt--;
				j--;
			}
			int sum=a[i]+a[j];
			if(sum==0)
				cnt--,i++,j--;
			else if(sum<0)
				i++;
			else
				j--;
		}
		
			
		printf("%d\n",cnt);
	}
	return 0;
}
