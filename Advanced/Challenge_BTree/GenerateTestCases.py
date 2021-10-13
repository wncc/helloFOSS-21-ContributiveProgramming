N = 100000

f = open('inputs'+str(N)+'.in','w')
import random
import math
L = []

for i in range(0,N):
    if random.random()>=0.75 and len(L)!=0:
        n = min(math.floor(random.random()*len(L)),len(L)-1)  
        f.write('GET ' + str(L[n])+'\n')
    elif random.random() <= 0.75 and random.random() >= 0.3333 and len(L)!=0:
        n = min(math.floor(random.random()*len(L)),len(L)-1)
        f.write('DEL ' + str(L[n])+'\n')
        del L[n]
    else:
        x = random.randint(0,1000000)
        L.append(x)
        f.write('IN ' + str(x) + '\n')


f.close()
