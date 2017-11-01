#include <stdio.h> 

//definition
#define MOD 1000000007
#define MAX 100005
#define pi 3.14159265358979
 
#define llu long long unsigned
#define lld long long
#define ld long
 
#define fu(i,a,n) for(int i=a;i<n;i++)
#define fue(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>a;i--)
#define fde(i,n,a) for(int i=n;i>=a;i--)
#define fr(i,a) for(i=0;i<a;i++)
 
#define sf_d(n) scanf("%d",&n)
#define sf_ld(n) scanf("%ld",&n)
#define sf_lld(n) scanf("%lld",&n)
 
//end of definition


int main()
{
    int d;
    sf_d(d);
    if(d%2==0 && d!=2)
        printf("YES");
    else
        printf("NO");
    return 0;
}