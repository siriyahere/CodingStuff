#include <stdio.h>
#include<string.h>
	unsigned int  val[100];
unsigned int max3(unsigned  int a,unsigned  int b,unsigned int  c)
{
	if(a>b)
	{
		if(a>c)
			return a;
		else 
			return c;
	}
	else 
	{
	
		if(b>c)
		{		
			return b;
		}
		else
			return c;		
	}
	
}

unsigned int maxProductcut(int n)
{
	int i,j;

	//memset(val,0,sizeof(val));
	val[0]=val[1]=0;
	for(i=1;i<=n;i++)
	{
	//	printf("%d\n",val[i]);
		unsigned int maxi=0;
		for(j=0;j<=i/2;j++)
		{
			maxi=max3(maxi,(i-j)*j,val[i-j]*j);			
		}
		val[i]=maxi;
	}
	return val[n];
}

int main() {
	//code
	int tc;
	int n;
	scanf("%d",&tc);
	while(tc--)
	{
	    scanf("%d",&n);
	    
	    printf("%u",maxProductcut(n));
	}
	return 0;
}
