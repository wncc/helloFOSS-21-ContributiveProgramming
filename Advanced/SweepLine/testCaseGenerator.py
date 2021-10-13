import random
import math


def ccw(A,B,C):
    return (C[1]-A[1]) * (B[0]-A[0]) > (B[1]-A[1]) * (C[0]-A[0])

# Return true if line segments AB and CD intersect
def intersect(A,B,C,D):
    return ccw(A,C,D) != ccw(B,C,D) and ccw(A,B,C) != ccw(A,B,D)


L = []
stack = []
N = 0
M = 0
dict = {}
nlim = 100000
mlim = 100000

while True:
    x1 = random.randint(-1000000,1000000)
    x2 = random.randint(-1000000,1000000)
    y1 = random.randint(-1000000,1000000)
    y2 = random.randint(-1000000,1000000)
    z = ((x1,y1),(x2,y2))
    L.append(z)
    N = N+1
    if N>=nlim:
        break
    for i in range(0,len(L)-1):
        if intersect(z[0],z[1],L[i][0],L[i][1]):
            M = M+1
            if M>=mlim:
                break

f = open('inputs.in','w')

f.write(str(N)+'\n')

for l in L:
    f.write(str(l[0][0])+' '+str(l[0][1])+' '+str(l[1][0])+' '+str(l[1][1])+'\n')

f.close()



