#include<stdio.h>
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n,i,j;
		scanf("%d",&n);
		
		int m=n<=6?6:n;
		unsigned long screen[m+1];
		for(i=1;i<=m;i++)
		{
			screen[i-1]=i;
		}
		for(i=7;i<=n;i++)
		{
			screen[i-1]=0;
			unsigned long max=0;
			for(j=i-3;j>=1;j--)
			{
				unsigned long temp=screen[j-1]*(i-j-1);
				if(temp>screen[i-1])
					screen[i-1]=temp;
			}
		//	screen[n-1]=max;
		}
		printf("%lu",screen[n-1]);
		printf("\n");
	}
	
	return 0;
}
