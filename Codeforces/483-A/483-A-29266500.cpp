#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	long long int l,r;
	cin>>l>>r;
	if(r-l<2)
	{
		printf("-1");
		return 0;
	}
	if(l&1)
		l++;
	if(l+2>r)
	{
		printf("-1");
		return 0;
	}
	cout<<l<<" "<<l+1<<" "<<l+2<<endl;
	return 0;
}