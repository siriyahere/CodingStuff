#include<stdio.h>
#include<math.h>
int main()
{
	int n,t;
	int f[50];
	f[0]=f[1]=f[2]=f[3]=1;
	for(int i=4;i<=41;i++)
		f[i]=f[i-1]+f[i-4];
	//printf("%d",f[41]);
	bool p[299915];
	for(int i=0;i<=f[41];i++)
		p[i]=true;
	for(int i=4;i<=f[41];i+=2)
		p[i]=false;
	for(int i=3;i<=sqrt(f[41]);i+=2)
	{
		for(int j=i;j*i<=f[41];j++)
			p[i*j]=false;
	}
	int count[299915];
	count[0]=count[1]=count[2]=0;
	for(int i=2;i<=f[41];i++)
		{
		count[i]=count[i-1];
		if(p[i])
		{
				count[i]++;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("\n%d",count[f[n]]);
	}
	
	return 0;
	
}
