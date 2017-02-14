#include<stdio.h>

int a[100];
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

void sort(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]<a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

int main()
{
//	int a[10]={-7,-4,-3,0,1,3,4,6,8,9};
	int a[6]={1, 10, 14, 14, 14, 15};
	//int tc;
	//scanf("%d",&tc);
	//while(tc--){
	
	int n=6;
	int k=6;
	
	sort(a,n);
//	for(int i=0;i<n;i++)
//		printf("%d\t",a[i]);
	int lmin,lmax;
	lmin=a[0];
	lmax=a[n-1];
	if(lmax-lmin<k)
		printf("%d\n",lmax-lmin);
	else
	{
		int temp[3];
		//int nmin=lmin+k;
		int nmin=min(lmin+k,lmax-k);
		int nmax=max(lmax-k,lmin+k);
		a[0]=nmin;
		a[n-1]=nmax;
		for(int i=1;i<n-1;i++)
		{
			if(a[i]<nmin)
			{
				a[i]+=k;
			}
			else if(a[i]>nmax)
			{
				a[i]-=k;
			}
			else
			{
				if((a[i]-nmin)>(nmax-a[i]))
				{
					a[i]-=k;
				}
				else
					a[i]+=k;
			}
			nmin=min(a[i],nmin);
			nmax=max(a[i],nmax);
		}
		printf("%d\n",nmax-nmin);
	}
}
//	for(int i=0;i<n;i++)
//		printf("%d\t",a[i]);
	
	return 0;
}
