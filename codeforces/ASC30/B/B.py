C=[[0 for i in range(300)] for j in range(300)]
for i in range(0,210):
	C[i][0]=1
for i in range(1,210):
	for j in range(1,210):
		C[i][j]=C[i-1][j-1]+C[i-1][j]
fac=[0 for i in range(300)]
fac[0]=1
for i in range(1,210):
	fac[i]=fac[i-1]*i
f=file('derangements.in')
n=int(f.readline())
f.close()
ans=0
for i in range(0,n+1):
	ans=ans+C[n][i]*(2**(n-i))*((-1)**i)*fac[n-i];
f=file('derangements.out','w')
f.write(str(ans))
f.close()
