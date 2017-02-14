#include<stdio.h>
#include<string.h>
char str[1001];
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%s",str);
		int n=strlen(str);
		int i,count=0;
		for(i=1;i<n;i++)
		{
			if(str[i]==str[i-1])
			{
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
