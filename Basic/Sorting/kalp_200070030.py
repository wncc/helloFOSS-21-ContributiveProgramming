f=open("input.txt","r")
lines=f.readlines()

t=int(lines[0])

for x in range(t):
    n=int(lines[2*x+1])
    seq=lines[2*x+2].split()
    ans=[]

    for i in ['XS','S','M','L','XL','XXL','XXXL']:
        count=seq.count(i)
        for j in range(count):
            ans.append(i)
    s=0
    for i in range(n):
        if ans[i]!=seq[i]:
            s+=1
    print((s+1)//2)
    print(' '.join(ans))
