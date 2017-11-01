#include <stdio.h>
 
//definition
#define gc() getchar_unlocked()
#define pc() putchar_unlocked()
 
#define MOD 1000000007
#define MAX 100005
#define pi 3.14159265358979
 
#define llu long long unsigned
#define lld long long
#define ld long
 
#define fu(i,a,n) for(i=a;i<n;i++)
#define fue(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>a;i--)
#define fde(i,n,a) for(i=n;i>=a;i--)
#define fr(i,a) for(i=0;i<a;i++)
#define fe(i,a) for(i=0;i<=a;i++)
 
//end of definition
 
//input
 
int scan_d()	{int n;scanf("%d",&n);return n;}
ld scan_ld()	{ld n;scanf("%ld",&n);return n;}
lld scan_lld()	{lld n;scanf("%lld",&n);return n;}
llu sacn_llu()	{llu n;scanf("%llu",&n);return n;}
 
//end of input
 
//output
 
//no line break
void print_d(int n)		{printf("%d",n);}
void print_ld(ld n)		{printf("%ld",n);}
void print_lld(lld n)	{printf("%lld",n);}
void print_llu(llu n)	{printf("%llu",n);}
 
//new line
void println_d(int n)	{printf("%d\n",n);}
void println_ld(ld n)	{printf("%ld\n",n);}
void println_lld(lld n)	{printf("%lld\n",n);}
void println_llu(llu n)	{printf("%llu\n",n);}
 
//special char
char sp;
void printsp_d(int n)	{printf("%d%c",n,sp);}
void printsp_ld(ld n)	{printf("%ld%c",n,sp);}
void printsp_lld(lld n)		{printf("%lld%c",n,sp);}
void printsp_llu(llu n)		{printf("%llu%c",n,sp);}
 
//end of output

int ar[100001],n,c;

int compfunc(const void *l,const void *m)
{
    return(*(int*)l-*(int*)m);
}


int fnc(int x)
{
	int i,temp;
	temp=1;
	lld prev;
	prev=ar[0];
	fu(i,1,n)
	{
		if(ar[i]-prev>=x)
		{
			temp++;
			if(temp==c)
				return 1;
			prev=ar[i];
		}
	}
	return 0;
}


void binsearch()
{
	int l,r,mid;
	l=0;
	r=ar[n-1];
	while(l<r)
	{
		mid=(l+r)/2;
		if(fnc(mid)==1)
			l=mid+1;
		else
			r=mid;
	}
	println_lld(l-1);
}

int main()
{
/*	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	lld t,i;
	t=scan_lld();
	while(t--)
	{
		n=scan_d();
		c=scan_d();
		fr(i,n)
			ar[i]=scan_d();
		qsort(ar,n,sizeof(int),compfunc);
		binsearch();
	}
	return 0;
}