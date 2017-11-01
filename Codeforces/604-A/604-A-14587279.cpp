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

//macros
#define vi      vector < int >
#define vld     vector < ld >
#define vlld    vector < lld >
#define pii     pair <int, int>
#define plld    pair<lld, lld>
#define vpii    vector< pii >
#define vplld   vector< plld >

#define gc      getchar
#define pc      putchar
#define rr      freopen("input.txt", "r", stdin)
#define wr      freopen("output.txt", "w", stdout)

//important constants
#define MOD     1000000007
#define INF     1LL<<57LL
#define MAX     1e6
#define pi      M_PI
#define ESP     (1e-9)

//looping
#define fr(i,a)             for(i=0;i<a;i++)
#define fe(i,a)             for(i=0;i<=a;i++)
#define fu(i,a,n)           for(i=a;i<n;i++)
#define fue(i,a,n)          for(i=a;i<=n;i++)
#define fd(i,n,a)           for(i=n;i>a;i--)
#define fde(i,n,a)          for(i=n;i>=a;i--)
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

//input output
#define sd(n)       scanf("%d",&n)
#define sld(n)      scanf("%ld",&n)
#define slld(n)     scanf("%lld",&n)
#define pfd(n)      printf("%d",n)
#define pfld(n)     printf("%ld",n)
#define pflld(n)    printf("%lld",n)

//shortcut
#define ff          first
#define ss          second
#define sz(a)       ((int)(a.size()))
#define clr         clear()
#define len(a)      ((int)a.length())
#define pb          push_back
#define mp          make_pair
#define gcd(a,b)    __gcd(a,b)
#define all(vi)     vi.begin(), vi.end()
#define mem(i,n)    memset(i,n,sizeof(i))
#define IOS         ios_base::sync_with_stdio(false); cin.tie(NULL)

#define imax    numeric_limits<int>::max()
#define imin    numeric_limits<int>::min()
#define ldmax   numeric_limits<ld>::max()
#define ldmin   numeric_limits<ld>::min()
#define lldmax  numeric_limits<lld>::max()
#define lldmin  numeric_limits<lld>::min()
//end of definition

//fast input

int scan_d()        {register int c=gc();int x=0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}return x;}
ld scan_ld()        {register ld c=gc();ld x=0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}return x;}
lld scan_lld()      {register lld c=gc();lld x=0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}return x;}
llu scan_llu()      {register llu c=gc();llu x=0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}return x;}

//end of fast input

//fast output

//no line break
void print_d(int n)         {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<10);}
void print_ld(ld n)         {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void print_lld(lld n)       {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}
void print_llu(llu n)       {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}

//new line
void println_d(int n)       {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void println_ld(ld n)       {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[12];output_buffer[11]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<12);}
void println_lld(lld n)     {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
void println_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}

//special char
char sp;
void printsp_d(int n)       {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[11];output_buffer[10]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void printsp_ld(ld n)       {if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[12];output_buffer[11]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<12);}
void printsp_lld(lld n)     {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
void printsp_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}

//end of fast output

int fnc(int x,int m,int w)
{
    int temp;
    temp=(((250-m)*x)-(12500*w))/250;
    return temp;
}

int main()
{
    int w1,w2,w3,w4,w5,m1,m2,m3,m4,m5,h1,h2,ans,temp;
    m1=scan_d();
    m2=scan_d();
    m3=scan_d();
    m4=scan_d();
    m5=scan_d();
    w1=scan_d();
    w2=scan_d();
    w3=scan_d();
    w4=scan_d();
    w5=scan_d();
    h1=scan_d();
    h2=scan_d();
    ans=0;
    ans+=max(150,fnc(500,m1,w1));
    ans+=max(300,fnc(1000,m2,w2));
    ans+=max(450,fnc(1500,m3,w3));
    ans+=max(600,fnc(2000,m4,w4));
    ans+=max(750,fnc(2500,m5,w5));
    temp=(h1*100)-(h2*50);
    println_d(ans+temp);
    return 0;
}