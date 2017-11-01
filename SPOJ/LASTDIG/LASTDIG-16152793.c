#include<bits/stdc++.h>
using namespace std;

int fnc(int a,long long b,int MOD)
{
	int ans=1;
	while(b!=0)
	{
		if(b&1) //b & 1 return 1 if the number is odd 
			ans=((ans%MOD)*(a%MOD)%MOD);
		a*=a;
		a%=MOD;
		b>>=1;//integer division by 2;
	}
	return ans;
}
int main()
{
	int t,a;
	long long b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a==0)
		{
			puts("0");
			continue;
		}
		else if(b==0)
		{
			puts("1");
			continue;
		}
		else
			printf("%d\n",fnc(a,b,10));
	}
	return 0;
}
