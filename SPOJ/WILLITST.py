n=int(raw_input())
f=1;
while n>1:
	if(n%2==0):
		n/=2;
	else:
		n=3*n+3;
	if(n==3):
		f=0;
		break;
if f==1:
	print("TAK");
else:
	print("NIE");