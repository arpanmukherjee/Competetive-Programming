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
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

#ifndef ONLINE_JUDGE
    bool debug = false;
#else
    bool debug = true;
#endif

typedef vector <int> vi;
typedef pair< int ,int > pii;


//definition
#define gc() getchar_unlocked()
#define pc putchar_unlocked

#define MOD 1000000007
#define MAX 100005
#define pi 3.14159265358979

#define llu long long unsigned
#define lld long long
#define ld long

#define len length()

#define fu(i,a,n) for(i=a;i<n;i++)
#define fue(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>a;i--)
#define fde(i,n,a) for(i=n;i>=a;i--)
#define fr(i,a) for(i=0;i<a;i++)
#define fe(i,a) for(i=0;i<=a;i++)

#define sf_d(n) scanf("%d",&n)
#define sf_ld(n) scanf("%ld",&n)
#define sf_lld(n) scanf("%lld",&n)

#define all(vi) vi.begin(), vi.end()
#define pb push_back
#define sz size()
#define mp make_pair
//end of definition

int main()
{
    string x,y;
    cin>>x>>y;
    int ln=x.sz,i;
    bool f=true;
    fde(i,ln-1,0)
    {
        if(x[i]!=y[ln-i-1])
        {
            f=false;
            break;
        }
    }
    if(f)
        printf("YES");
    else
        printf("NO");
    return 0;
}