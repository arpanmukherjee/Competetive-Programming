#include <bits/stdc++.h>

bool ispresent(int a,int ar[],int n)
{
	int i;
	bool f=true;
	for(i=0;i<n;i++)
	{
		if(ar[i]==a)
		{
			f=false;
			break;
		}
	}
	return f;
}

int main()
{
	int a,t,i,temp,n;
	long long int b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&a,&b);
		if(a==0 && b==0)
			printf("0\n");
		else if(b==0)
			printf("1\n");
		else
		{
			int ar[10000]={0};
			a%=10;
			i=1;
			temp=pow(a,2);
			temp%=10;
			ar[0]=a;
			while(1)
			{
				if(ispresent(temp,ar,i))
				{
					ar[i]=temp;
					temp*=a;
					temp%=10;
					i++;
				}
				else
					break;
			}
			b--;
			b%=i;
			printf("%d\n",ar[b]);
		}
	}
	return 0;
}