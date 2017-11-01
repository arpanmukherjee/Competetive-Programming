t=int(raw_input());
while t>0:
	x=raw_input().split();
	a,b=int(x[0]),int(x[1]);
	print(pow(a,b,10));
	t=t-1;