import sys
for n in sys.stdin.readlines():
	n=int(n);
	if n==1:
		print "1";
	else:
		n=n-1;
		print(2*n);