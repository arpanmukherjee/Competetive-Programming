#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<math.h>
const long long inf=1e17;

#define forn(i,n) for(int i=0;i<n;i++)
#define ll long long
using namespace std; 
ll mod=pow(10,9)+7; 
int main()
{ 
	int t; 
	ll x,n,p; 
	scanf("%d",&t); 
	while(t--)
	{ 
		
		scanf("%lld",&x);
        n=ceil((-1+sqrt(8*x+1))/2);
        p = x - n*(n-1)/2;
        if (n%2==0)
            printf("TERM %lld IS %lld/%lld\n",x , p , n+1-p);    
        else
            printf("TERM %lld IS %lld/%lld\n",x, n + 1 -p ,p);   
	} 
	return 0; 
}