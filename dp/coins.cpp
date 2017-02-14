#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,x,y;
	int n,m;
	int S[100];
	scanf("%d%d",&m,&n); //3 4
	for(i=0;i<m;i++)
		scanf("%d",&S[i]); //1 2 3
	int table[n+1];
	memset(table,0,sizeof(table));
	table[0]=1;
	for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];
    for(int i=0; i<n; i++)
		printf("%d\n",table[i]);
    printf("%d",table[n]);
}
