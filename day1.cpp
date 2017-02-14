#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char str[100][101];
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int a[26]={0};
    int tc;
    scanf("%d",&tc);
    for(int i=0;i<tc;i++)
        scanf("%s",&str[i]);
   /* for(int i=0;i<tc;i++)
        printf("%s",str[i]);
    */
    
    for(int i=0;i<tc;i++)
    {
    	int b[26]={0};
        for(int j=0;str[i][j];j++)
            {
            	
            	int c= str[i][j];
       //     	printf("%d",c);
       		
            if(b[c-97]==0)
            {
			
                a[c-97]++;
                b[c-97]=1;
        }
        }
        
    }
    int cnt=0;
    for(int i=0;i<tc;i++)
       {
//		printf("%d\n",a[i]);
		 if(a[i]==tc)
            cnt++;
    }
    printf("%d",cnt);
    return 0;
}
