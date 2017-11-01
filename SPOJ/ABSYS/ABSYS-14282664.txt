# your code goes here
t=int(raw_input());
while t>0:
	raw_input();
	a=raw_input().split();
	str='machula';
	if str in a[0]:
		print "%d + %s = %s" % (int(a[4]) - int(a[2]), a[2], a[4])
	elif str in a[2]:
		print "%s + %d = %s" % (a[0] , int(a[4])-int(a[0]) , a[4])
	elif str in a[4]:
		print "%s + %s = %d" % (a[0] , a[2] , int(a[0]) + int (a[2]))
	t=t-1;