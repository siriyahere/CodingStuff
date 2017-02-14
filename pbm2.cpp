#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 

#include<iostream>
using namespace std;
int main() {

	long n;
    cin>>n;
    int s=0;
    int c[10]={0};
    int i,k=0;
    char str[20];
    for(i=n;i>0;)
    {
        c[i%10]++;
        i=i/10;
        s++;
    }
    bool f=true;
    
    for(i=9;i>=0;i--)
    {
        if(c[i]%2&&f)
        {
            str[s/2]=c[i];
        }
        
        for(;k<c[i]/2;k++)
        {
            str[0+k]='0'+i;
            str[s-1-k]='0'+i;
        }
    }
    str[s]='\0';
    cout<<str;
    
}
