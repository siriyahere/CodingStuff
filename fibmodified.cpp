#include<stdio.h>
unsigned long long fib[22];
int main()
{
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	fib[0]=a;
	fib[1]=b;
	for(int i=2;i<n;i++)
	{
		fib[i]=fib[i-1]*fib[i-1]+fib[i-2];
		
	}
	printf("%ulld\n",fib[n-1]);
	return 0;

}
