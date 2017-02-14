#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,x,y,tc;
	int n,m;
	int S[3]={1,2,3};
	scanf("%d",&tc); //3 4
	while(tc--){

		scanf("%d",&n);
		int table[n+1];
		memset(table,0,sizeof(table));
		table[0]=1;
		
		for(int i=0; i<3; i++)
        	for(int j=S[i]; j<=n; j++)
            	table[j] += table[j-S[i]];
    	for(int i=0; i<=n; i++)
			printf("%d\n",table[i]);
    	printf("%d\n",table[n]);
	}
	return 0;
}
