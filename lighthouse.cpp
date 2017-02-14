#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
	
	int n;
	scanf("%d",&n);
	int i,j,k,count,final;
	char ch;
	int a[n];
	for(i=0;i<n;i++)
	{
		count=0;
		char s[n+1];
		
		scanf("%s",s);
		printf("\n%s\n",s);
			for(j=0;j<n;j++)
			{
				
				if(s[j]==42)
					count++;
			}
			a[i]=count;
		
	}
	for(j=0;j<n;j++)
		printf("%d\n",a[i]);	
	int prev=a[n/2];
	if(a[n/2])
	{
		for(j=0;j<n/2;j++)
		{
			if(a[n/2-j]==a[n/2+j])
			{
				
					if(a[n/2-j]==prev-2)
					{
							count++;
							prev=prev-2;
					}
					else
					{
						if(prev==1)
							break;
						else
							count=0;
					}
						
			}
		}
		final=count/2;
	}
	else
	{
		final=0;
	}
	
	printf("%d\n",final);   
	   
    return 0;
}
