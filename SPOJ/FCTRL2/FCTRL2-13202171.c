#include <stdio.h> 
int main()
{
	int n,t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		int a[500],carry=0,m=1,mul;
		a[0]=1;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<m;j++)
			{
				mul=(a[j]*i)+carry;
				carry=mul/10;
				a[j]=mul%10;
			}
			while(carry>0)
			{
				a[m]=carry%10;
				carry/=10;
				m++;
			}
		}
		for(i=m-1;i>=0;i--)
			printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}