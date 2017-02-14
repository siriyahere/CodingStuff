#include<stdio.h>
#include<strings.h>

unsigned long dp[1001];
unsigned long div=1000000007;
char c[1001];
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--){
		dp[0]=1;
		scanf("%s",c);
		int n=strlen(c);
		int last[26]={0};
		for(int i=1;i<=n;i++){
			
		//	dp[i]=dp[i-1]*2;
			if(last[c[i-1]-'a']==0)
			{
				dp[i]=(dp[i-1]*2)%(div);
			}
			else
			{
				dp[i]=((dp[i-1]%div)*2)%(div);
				dp[i]=(dp[i]%div - dp[last[c[i-1]-97]-1 ]%div)%div;
			}
			last[c[i-1]-97]=i;
			
		}
	/*	for(int i=0;i<=n;i++)
				printf("%d\n",dp[i]);
		for(int i=0;i<=5;i++)
				printf("%d\n",last[i]);*/
				
		printf("%d\n",dp[n]);
	}
	return 0;
}
