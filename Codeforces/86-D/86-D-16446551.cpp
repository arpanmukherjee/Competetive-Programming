#include <bits/stdc++.h>
	
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
#define vi 		vector < int >
#define vld 	vector < ld >
#define vlld 	vector < lld >
#define vllu 	vector < llu >
#define pii 	pair <int, int>
#define plld 	pair<lld, lld>
#define vpii 	vector< pii >
#define vplld 	vector< plld >

#define gc 		getchar
#define pc 		putchar
#define rr 		freopen("input.txt", "r", stdin)
#define wr 		freopen("output.txt", "w", stdout)

//important constants
#define MOD 	1000000007
#define INF 	1LL<<57LL
#define MAX 	1000001
#define pi 		M_PI
#define ESP 	(1e-9)

//looping
#define fr(i,a) 			for(i=0;i<a;i++)
#define fe(i,a) 			for(i=0;i<=a;i++)
#define fu(i,a,n) 			for(i=a;i<n;i++)
#define fue(i,a,n) 			for(i=a;i<=n;i++)
#define fd(i,n,a) 			for(i=n;i>a;i--)
#define fde(i,n,a) 			for(i=n;i>=a;i--)
#define tr(container, it) 	for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

//input output
#define sd(n) 		scanf("%d",&n)
#define sld(n) 		scanf("%ld",&n)
#define slld(n) 	scanf("%lld",&n)
#define pfd(n) 		printf("%d",n)
#define pfld(n) 	printf("%ld",n)
#define pflld(n) 	printf("%lld",n)

//shortcut
#define ff 			first
#define ss 			second
#define clr 		clear()
#define pb 			push_back
#define mp 			make_pair
#define gcd(a,b)  	__gcd(a,b)
#define sz(a) 		((int)(a.size()))
#define len(a) 		((int)a.length())
#define all(vi) 	vi.begin(), vi.end()
#define mem(i,n) 	memset(i,n,sizeof(i))
#define IOS 		ios_base::sync_with_stdio(false); cin.tie(NULL)

#define imax 	numeric_limits<int>::max()
#define imin 	numeric_limits<int>::min()
#define ldmax 	numeric_limits<ld>::max()
#define ldmin 	numeric_limits<ld>::min()
#define lldmax 	numeric_limits<lld>::max()
#define lldmin 	numeric_limits<lld>::min()
//end of definition

const int dx[]={0,1,0,-1,1,1,-1,-1,0};
const int dy[]={1,0,-1,0,-1,1,1,-1,0};

template<typename X> inline X square(const X& a) { return a * a; }

//fast input

int scan_d()		{bool minus = false;int result = 0;char ch;ch = gc();while (true){if (ch == '-') break;if (ch >= '0' && ch <= '9') break;ch = gc();}if (ch == '-') minus = true; else result = ch-'0'; while (true){ch = gc(); if (ch < '0' || ch > '9') break;result = (result<<3) + (result<<1) + (ch - '0');}if (minus) return -result; else return result;}
ld scan_ld()		{bool minus = false;ld result = 0;char ch;ch = gc();while (true){if (ch == '-') break;if (ch >= '0' && ch <= '9') break;ch = gc();}if (ch == '-') minus = true; else result = ch-'0'; while (true){ch = gc(); if (ch < '0' || ch > '9') break;result = (result<<3) + (result<<1) + (ch - '0');}if (minus) return -result; else return result;}
lld scan_lld()		{bool minus = false;lld result = 0;char ch;ch = gc();while (true){if (ch == '-') break;if (ch >= '0' && ch <= '9') break;ch = gc();}if (ch == '-') minus = true; else result = ch-'0'; while (true){ch = gc(); if (ch < '0' || ch > '9') break;result = (result<<3) + (result<<1) + (ch - '0');}if (minus) return -result; else return result;}
llu scan_llu()		{llu result = 0;char ch;ch = gc();while (true){if (ch == '-') break;if (ch >= '0' && ch <= '9') break;ch = gc();}result = ch-'0'; while (true){ch = gc(); if (ch < '0' || ch > '9') break;result = (result<<3) + (result<<1) + (ch - '0');}return result;}

//end of fast input

//fast output

//no line break
void print_d(int n)     	{if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<10);}
void print_ld(ld n)     	{if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void print_lld(lld n)     	{if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}
void print_llu(llu n)     	{int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<21);}

//new line
void println_d(int n)     	{if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void println_ld(ld n)     	{if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[12];output_buffer[11]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<12);}
void println_lld(lld n)     {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
void println_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}

//special char
char sp;
void printsp_d(int n)     	{if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[11];output_buffer[10]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<11);}
void printsp_ld(ld n)     	{if(n<0){n=-n;putchar('-');}int i=11;char output_buffer[12];output_buffer[11]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<12);}
void printsp_lld(lld n)     {if(n<0){n=-n;putchar('-');}int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}
void printsp_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<22);}

//end of fast output

int BLOCK_SIZE;
lld m[1000005],temp;
pair<plld,lld> q[200000];
lld ans[200000],a[200000];

inline bool cmp(pair<pii,int> a,pair<pii,int> b)
{
	if(a.ff.ff/BLOCK_SIZE != b.ff.ff/BLOCK_SIZE)
		return (a.ff.ff/BLOCK_SIZE)<(b.ff.ff/BLOCK_SIZE);
	return a.ff.ss<b.ff.ss;
}

inline void upd(lld x,lld bc)
{
	temp+= 2*bc*m[x]*x+x;
	m[x]+=bc;
}

inline void add(lld x)
{
	upd(x,1);
}

inline void remove(lld x)
{
	upd(x,-1);
}

int main()
{
	lld n,t,i,l,r;
	mem(m,0);
	scanf("%lld%lld",&n,&t);
	BLOCK_SIZE=sqrt(n);
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(i=0;i<t;i++)
	{
		scanf("%lld%lld",&l,&r);
		l--;
		r--;
		q[i].ff.ff=l;
		q[i].ff.ss=r;
		q[i].ss=i;
		/*q.pb(mp(l,r));
		ar.pb(mp(l,r));*/
	}
	sort(q,q+t,cmp);
	temp=0;
	l=0;
	r=-1;
	for(i=0;i<t;i++)
	{
		while(r>q[i].ff.ss)
		{
			remove(a[r]);
			r--;
			//cout<<r<<" "<<temp<<endl;
		}
		while(r<q[i].ff.ss)
		{
			r++;
			add(a[r]);
			//cout<<r<<" "<<temp<<endl;
		}
		while(l<q[i].ff.ff)
		{
			
			remove(a[l]);
			l++;
			//cout<<l<<" "<<temp<<endl;
		}
		while(l>q[i].ff.ff)
		{
			l--;
			add(a[l]);
			//cout<<l<<" "<<temp<<endl;
		}
		ans[q[i].ss]=temp;
	}
	for(i=0;i<t;i++)
		printf("%lld\n",ans[i]);
	return 0;
}