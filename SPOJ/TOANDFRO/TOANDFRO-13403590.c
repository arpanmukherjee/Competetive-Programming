#include <bits/stdc++.h>

using namespace std;

/*#ifndef ONLINE_JUDGE
    bool debug = false;
#else
    bool debug = true;
#endif*/

typedef vector <int> vi;
typedef pair <int, int> pii;
typedef istringstream iss;
typedef ostringstream oss;

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

#define sf_d(n) scanf("%d",&n)
#define sf_ld(n) scanf("%ld",&n)
#define sf_lld(n) scanf("%lld",&n)

#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define all(vi) vi.begin(), vi.end()
#define len length()
#define pb push_back
#define sz size()
#define mp make_pair
#define clr clear()
#define ff first
#define ss second
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define ldmax numeric_limits<ld>::max()
#define ldmin numeric_limits<ld>::min()
#define lldmax numeric_limits<lld>::max()
#define lldmin numeric_limits<lld>::min()
//end of definition

//fast input

int scan_d()    {int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
ld scan_ld()    {int ip=getchar_unlocked(),flag=1;ld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
lld scan_lld()    {int ip=getchar_unlocked(),flag=1;lld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
llu scan_llu()    {int ip=getchar_unlocked();llu ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}

//end of fast input

//fast output

//no line break
void print_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
void print_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void print_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
void print_llu(llu n)     {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}

//new line
void println_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void println_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[12];output_buffer[11]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<12);}
void println_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
void println_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}

//special char
char sp;
void printsp_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void printsp_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[12];output_buffer[11]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<12);}
void printsp_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
void printsp_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}

//end of fast output

int main()
{
    string str;
    int m,n,i,j,l;
    m=scan_d();
    while(m!=0)
    {
        cin>>str;
        n=str.len/m;
        char a[n][m];
        l=0;
        fr(i,n)
        {
            if(i%2==0)
            {
                fr(j,m)
                    a[i][j]=str[l++];
            }
            else
            {
                fde(j,m-1,0)
                    a[i][j]=str[l++];
            }
        }
        fr(j,m)
        {
            fr(i,n)
            {
                printf("%c",a[i][j]);
            }
        }
        printf("\n");
        m=scan_d();
    }
    return 0;
}