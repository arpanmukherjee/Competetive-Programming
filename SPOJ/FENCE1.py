import math
l=int(raw_input());
while l!=0:
	ans=(l*l)/(2*math.pi);
	print("%.2f" % round(ans,2))
	l=int(raw_input());