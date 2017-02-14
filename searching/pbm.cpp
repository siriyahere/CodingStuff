#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include<iostream>
using namespace std;
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
    int cnt=1;
    int tab=0;
    int r=0;
    for(i=0;i<n;i++)
    {
    	if(a[i]<temp)
    	{
    		cnt++;	
    		if(r!=0)
    			cnt+=r;
    		r=0;
		}
		if(a[i]==temp)
			r++;
		
    	//else
    	//	tab++;
	}
	for(i=0;i<pos;i++)
	{
			if(a[i]<temp)
    		cnt++;
	}
	cout<<(n-cnt)*2;
	return 0;
}
