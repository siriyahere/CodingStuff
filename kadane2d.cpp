#include<stdio.h>

void print(int a[100][100],int m,int n)
{
	for(int i=0;i<m;i++)
		{
		for(int j=0;j<n;j++)
			printf("%d  ",a[i][j]);
		printf("\n");
	}
}

int kadane(int * a,int *p,int *q,int m)
{
	int max_so_far=a[0];
	int max_end =a[0];
	for(int i=1;i<m;i++)
	{
		//printf("%d",a[i]);
		
		if(max_end+a[i]<a[i])
		{
			max_end=a[i];	
			*p=i;
			
		}
		else
		{
			max_end=a[i]+max_end;	
			
			
		}
		
		if(max_so_far<max_end)
		{
			max_so_far=max_end;
			*q=i;
		}
	}
	return max_so_far;
}



void kadane2d(int a[100][100],int m,int n)
{
	int left,right,top,bottom,start,finish,sum,maxsum=-90;
	for(int l=0;l<n;l++)
	{
		int temp[10]={0};
		for(int r=l;r<n;r++)
		{
			for(int row=0;row<m;row++)
				temp[row]+=a[row][r];
			sum=kadane(temp,&start,&finish,m);
		//	printf("after kadane");
			if(sum>maxsum)
			{
				maxsum=sum;
				left=l;
				right=r;
				top=start;
				bottom=finish;
			}
		}
		//printf("outside r");
	}
//	printf("\n%d %d %d %d",left,right,top,bottom);
//	printf("\n%d",maxsum);
printf("%d\n",top-bottom);
}


int main()
{
	int a[100][100];
	int m,n;
	int tc;
	scanf("%d",&tc);
	while(tc--){
	
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
//	print(a,m,n);
	kadane2d(a,m,n);
}
	return 0;
	
}
