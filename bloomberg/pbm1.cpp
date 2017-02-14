#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include<iostream>
using namespace std;

int swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
	
}

int partition(int a[],int p,int q,int n)
{
	int key=a[n];
	int pos=p-1;
	int i;
	for(i=p;i<q;i++)
	{
		if(a[i]>=key&&a[i]<20)
		{
			pos=pos+1;
			swap(&a[i],&a[pos]);
		}	
	}
	swap(&a[pos+1],&a[q]);
	return pos+1;
}

int main() {
    
    int n;
    int pos;
    int i;
    cin>>n;
    cin>>pos;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    int temp=a[pos];
    int cnt=0;
    for(i=0;i<pos;i++)
		if(a[i]==temp)
			cnt++;
	for(i=pos+1;;i++)
		if(a[i]==temp)
			
	 /*for(i=0;i<pos;i++)
		if(a[i]<=temp)
			cnt--;*/
					
    int final=partition(a,0,n,pos);
	//for(i=0;i<pos;i++)
	//	if(a[i]==temp)
			
	cout<<(final-cnt)*2;
	
    return 0;
}

