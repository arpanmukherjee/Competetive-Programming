I=lambda:map(int,raw_input().split())
s,n=I()
for x,y in sorted(I()for z in[0]*n):s=(s+y)*(x<s)
print"YNEOS"[s==0::2]