#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t,i,ans,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n==1)
			printf("0\n");
		else
		{
			ans=1;
			for(i=2;i<=sqrt(n);i++)
			{
				if(n%i==0)
				{
					if(i==n/i)
						ans+=i;
					else
						ans+=(i+n/i);
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}