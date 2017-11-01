#include <bits/stdc++.h>
using namespace std;


struct query
{
	int left,right,id;
}q[200005];

int n,t,i,l,r,temp,ans[200005],a[300005],m[1000005],BLOCK_SIZE ;

inline bool compare(query a,query b)
{
	int x,y;
	x=a.left/BLOCK_SIZE;
	y=b.left/BLOCK_SIZE;
	if(x!=y)
		return x<y;
	return (a.right<b.right);
}

inline void add(int x)
{
	m[x]++;
	if(m[x]==1)
		temp++;
}

inline void remove(int x)
{
	m[x]--;
	if(m[x]==0)
		temp--;
}

int main()
{
	scanf("%d",&n);
	BLOCK_SIZE=sqrt(n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d %d",&l,&r);
		l--;
		r--;
		q[i].left=l;
		q[i].right=r;
		q[i].id=i;
	}
	sort(q,q+t,compare);
	l=temp=0;
	r=-1;
	for(i=0;i<t;i++)
	{
		while(l<q[i].left)
		{
			remove(a[l]);
			l++;
		}
		while(l>q[i].left)
		{
			l--;
			add(a[l]);
		}
		while(r>q[i].right)
		{
			remove(a[r]);
			r--;
		}
		while(r<q[i].right)
		{
			r++;
			add(a[r]);
		}
		ans[q[i].id]=temp;
	}
	for(i=0;i<t;i++)
		printf("%d\n",ans[i]);
	return 0;
}
