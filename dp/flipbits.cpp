#include<stdio.h>
int a[10001];
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	int tc;
	int n;
	scanf("%d",&tc);
	while(tc--){
	//-1 1 1 1 -1
	//-1 1 1 -1 1 
		int def=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==0)
				a[i]=1;
			else if(a[i]==1)
				a[i]=-1;	
		}	
		int max_so_far=0;
		int max_end=0;
		int temp=0;
		for(int i=0;i<n;i++)
		{
			max_end=a[i]+max_end;
			if(max_end<0){
			
				max_end=0;
			}
			else if(max_so_far<max_end){
				
				
				max_so_far=max_end;
			//	temp=i;
			}	
		}
		printf("%d\n",max_so_far);
	}
	return 0;
}
