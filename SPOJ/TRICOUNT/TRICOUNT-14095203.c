#include <stdio.h>
int main()
{
	int t;
	long long unsigned n,i,ans,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%llu\n",(n*(n+2)*(2*n+1))/8);
	}
	return 0;
}