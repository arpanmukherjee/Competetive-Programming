import sys
for n in sys.stdin.readlines():
	n=int(n);
	if n==1 or n==0:
		print n
	else:
		n=n-1;
		print(2*n);