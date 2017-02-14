#include<stdio.h>
#include<string.h>
int dp[100][100];
void initdp(int l)
{
    int i,j;
	for(i=0;i<l;i++)
		for( j=0;j<l;j++)
			dp[i][j]=-1;
}
int find(char *str,int i,int j)
{
	if(dp[i][j] != -1)
		return dp[i][j];
	if(i==j) 
	{
		dp[i][j]=0;
		return 0;
	}
	else if(i>j) 
	{
		dp[i][j]=65535;
		return 65535;
	}
	else if(i==j-1)
	{
		if(str[i]==str[j])
			return 0;
		else
			return 1;
	}

	
	if(str[i]==str[j])
		{
		  dp[i][j]=  find(str,i+1,j-1);
		}
	else
	{
		int ih=find(str,i,j-1);
		int hi=find(str,i+1,j);
		if(ih<hi)
		{
		    dp[i][j]=ih+1;
	//		return ih+1;
		}
		else{
		    dp[i][j]=hi+1;
	//	return hi+1;
		}
	}
	return dp[i][j];
}
void printdp(int l)
{
	int i,j;
	for(i=0;i<l;i++)
	{
		for(j=0;j<l;j++)
			printf("%d\t",dp[i][j]);
		printf("\n");
	}
}
int main()
{
	int tc;
	scanf("%d",&tc);

	while(tc--){
		
			char str[105];
			scanf("%s",str);
			int l= strlen(str);
			initdp(l+1);
			printf("%d\n",find(str,0,l-1));
		//	printdp(l);
	}
	return 0;
}
