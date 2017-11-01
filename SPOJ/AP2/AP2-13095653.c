#include <stdio.h>
int main()
{
	unsigned long long int t,a,d,i,n,t1,t2,sum;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&t1,&t2,&sum);
		n=(sum*2)/(t1+t2);
		d=(t2-t1)/(n-5);
		a=t1-(2*d);
		printf("%lld\n",n);
		for(i=1;i<=n;i++)
			printf("%lld ",(a+((i-1)*d)));
		printf("\n");
	}
	return 0;
}