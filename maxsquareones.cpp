#include<stdio.h>

int min(int a,int b,int c)
{
	if(a<b)
	{
		if(a<c)
			return a;
		else
			return c;
	}
	else
	{
		if(b<c)
			return b;
		else
			return c;
	}
}

void print(int a[100][100],int m,int n)
{
	for(int i=0;i<m;i++)
		{
		for(int j=0;j<n;j++)
			printf("%d  ",a[i][j]);
		printf("\n");
	}
	printf("\ndone\n");
}



void matrix(int a[100][100],int m,int n)
{
	int s[100][100];
	for(int i=0;i<m;i++)
		s[i][0]=a[i][0];
	for(int j=0;j<n;j++)
		s[0][j]=a[0][j];
	int max=0,row=0,col=0;
	
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(a[i][j]==1)
				s[i][j]=min(s[i][j-1],s[i-1][j],s[i-1][j-1])+1;
			else
				s[i][j]=0;
			if(s[i][j]>max)
			{
				max=s[i][j];
				row=i;
				col=j;
			}
		}
	}
	
	print(s,m,n);
	for(int i = row; i > row - max; i--)
  {
    for(int j = col; j > col - max; j--)
    {
      printf("%d ", a[i][j]);
    }  
    printf("\n");
  }  
    
	
}



int main()
{
	int a[100][100];
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	print(a,m,n);
	matrix(a,m,n);
	return 0;
	
}
