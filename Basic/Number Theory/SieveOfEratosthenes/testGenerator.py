N = 10000000
NUM = 0
LIM = 1000000
L = []
S = []
dict = {}
import random
import math
while NUM<=LIM:
    if random.random()>0.6 and len(S)>0:
        x = math.floor(random.random()*len(S))
        L.append(('-',S[x]))
        dict[S[x]] = 0
        del S[x]
        NUM = NUM+1
    else:
        t = 1+ math.floor(random.random()*N)
        while t in dict.keys() and dict[t]==1:
        	t = 1+ math.floor(random.random()*N)
        L.append(('+',t))
        S.append(t)
        dict[t] = 1
        NUM = NUM+1

f = open('inputs.in','w')

f.write(str(NUM)+'\n')

for l in L:
    f.write(l[0]+' '+str(l[1])+'\n')

f.close()


