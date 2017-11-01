#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
 
using namespace std;
 
#ifndef ONLINE_JUDGE
	bool debug = false;
#else
	bool debug = true;
#endif
 
typedef long long unsigned llu;
typedef long long lld;
typedef long ld;

//definition
#define vi vector < int >
#define vld vector < ld >
#define vlld vector < lld >
#define pii pair <int, int>
#define plld pair<lld, lld>
#define vpii vector< pii >
#define vplld vector< plld >

#define gc getchar_unlocked
#define pc putchar_unlocked
#define rr freopen("input.txt", "r", stdin)
#define wr freopen("output.txt", "w", stdout)

//important constants
#define MOD 1e9+7
#define MAX 1e6
#define pi 3.14159265358979
#define ESP (1e-9)

//looping
#define fr(i,a) for(i=0;i<a;i++)
#define fe(i,a) for(i=0;i<=a;i++)
#define fu(i,a,n) for(i=a;i<n;i++)
#define fue(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>a;i--)
#define fde(i,n,a) for(i=n;i>=a;i--)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

//input output
#define sd(n) scanf("%d",&n)
#define sld(n) scanf("%ld",&n)
#define slld(n) scanf("%lld",&n)
#define pfd(n) printf("%d",n)
#define pfld(n) printf("%ld",n)
#define pflld(n) printf("%lld",n)

#define ff first
#define ss second
#define sz size()
#define clr clear()
#define len length()
#define pb push_back
#define mp make_pair
#define gcd(a,b)  __gcd(a,b)
#define all(vi) vi.begin(), vi.end()
#define mem(i,n) memset(i,n,sizeof(i))
#define IOS ios_base::sync_with_stdio(false)

#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define ldmax numeric_limits<ld>::max()
#define ldmin numeric_limits<ld>::min()
#define lldmax numeric_limits<lld>::max()
#define lldmin numeric_limits<lld>::min()
//end of definition

//fast input

int scan_d()		{register int c=gc();int x=0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}return x;}
ld scan_ld()		{register ld c=gc();ld x=0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}return x;}
lld scan_lld()		{register lld c=gc();lld x=0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}return x;}
llu scan_llu()		{register llu c=gc();llu x=0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}return x;}

//end of fast input

//fast output

//no line break
void print_d(int n)     {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<10);}
void print_ld(ld n)     {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void print_lld(lld n)     {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}
void print_llu(llu n)     {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}

//new line
void println_d(int n)     {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void println_ld(ld n)     {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[12];output_buffer[11]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<12);}
void println_lld(lld n)     {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
void println_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}

//special char
char sp;
void printsp_d(int n)     {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[11];output_buffer[10]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void printsp_ld(ld n)     {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[12];output_buffer[11]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<12);}
void printsp_lld(lld n)     {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
void printsp_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}

//end of fast output
lld n;

void upd(lld a[],lld i,lld v)
{
	while(i<=n)
	{
		a[i]+=v;
		i+=(i&(-i));
	}
}

lld getval(lld a[],lld i)
{
	lld temp=0;
	while(i>0)
	{
		temp+=a[i];
		i-=(i&(-i));
	}
	return temp;
}

lld get(lld b1[],lld b2[],lld i)
{
	return (getval(b1,i)*i - getval(b2,i));
}

void update(lld b1[],lld b2[],lld l,lld r,lld v)
{
	upd(b1,l,v);
	upd(b1,r+1,-v);
	upd(b2,l,v*(l-1));
	upd(b2,r+1,-v*r);
}

lld query(lld b1[],lld b2[],lld l,lld r)
{
	return (get(b1,b2,r)-get(b1,b2,l-1));
}

int main()
{
	lld t,i,x,l,r,q,v;
	t=scan_lld();
	while(t--)
	{
		n=scan_lld();
		q=scan_lld();
		lld b1[n+1],b2[n+1];
		fr(i,n+1)
			b1[i]=b2[i]=0;
		while(q--)
		{
			x=scan_lld();
			if(x==0)
			{
				l=scan_lld();
				r=scan_lld();
				v=scan_lld();
				update(b1,b2,l,r,v);
			}
			else
			{
				l=scan_lld();
				r=scan_lld();
				println_lld(query(b1,b2,l,r));
			}
		}
	}
	return 0;
}
