def getnums(n):
    list = [1 for i in range(0,n+1)]
    for i in range(2, n+1):
        if list[i]==1:
            for j in range(i*i, n+1, i):
                list[j]=0
    L = []
    for i in range(0,n+1):
        if list[i]==1:
            L.append(i)
    return L

X = getnums(10000000)
import random
import math
random.shuffle(X)
N = 0
Nlim = 1000000
res = []
i = 0
while N<=Nlim and i<len(X)-3:
    print(N,'numbers added')
    t = random.randint(1,3)
    Z = X[i:i+t]
    u = 1
    for j in range(0,t):
        u = u * (Z[j]**(random.randint(1,2)))
        if u >= 10000000000000:
            break
    i = i+t
    if u<=1000000000000:
        res.append((math.floor(u*random.random()),u))
        N = N+1

f = open('inputs.in','w')
f.write(str(N)+'\n')
for r in res:
    f.write(str(r[0])+' '+str(r[1])+'\n')

f.close()
