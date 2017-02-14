#include<stdio.h>
#include<string.h>
int main()
{
	unsigned long long i,j,x,y,tc;
	unsigned  long long n,m;
	//int S[3]={1,2,3};
	scanf("%d",&tc); //3 4
	while(tc--){

		scanf("%d",&n);
		unsigned long long table[n+1];
		memset(table,0,sizeof(table));
		table[0]=1;
		
		table[1]=1;
		table[2]=2;
		for(i=3;i<=n;i++)
		{
			table[i]=table[i-1]+table[i-2];
		}
    /*	for(int i=0; i<=n; i++)
			printf("%d\n",table[i]);*/
    	printf("%llu\n",table[n]);
	}
	return 0;
}
