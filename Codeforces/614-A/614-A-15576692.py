l,r,k=map(int, raw_input().split())
temp=1
f=False
while temp<l:
	temp=temp*k
while temp<=r:
	f=True
	print temp
	temp=temp*k;
if f==False:
	print "-1"