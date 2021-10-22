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
    m={}
    m['XS']={'XS':0,'S':0,'M':0,'L':0,'XL':0,'XXL':0,'XXXL':0}
    m['S']={'XS':0,'S':0,'M':0,'L':0,'XL':0,'XXL':0,'XXXL':0}
    m['M']={'XS':0,'S':0,'M':0,'L':0,'XL':0,'XXL':0,'XXXL':0}
    m['L']={'XS':0,'S':0,'M':0,'L':0,'XL':0,'XXL':0,'XXXL':0}
    m['XL']={'XS':0,'S':0,'M':0,'L':0,'XL':0,'XXL':0,'XXXL':0}
    m['XXL']={'XS':0,'S':0,'M':0,'L':0,'XL':0,'XXL':0,'XXXL':0}
    m['XXXL']={'XS':0,'S':0,'M':0,'L':0,'XL':0,'XXL':0,'XXXL':0}
    for i in range(n):
        if ans[i]!=seq[i]:
            m[ans[i]][seq[i]]+=1

    ans_swaps=0
    for i in m.keys():
        for j in m[i].keys():
            if m[i][j]>0:
                temp=min(m[i][j],m[j][i])
                m[i][j]-=temp
                m[j][i]-=temp
                ans_swaps+=temp
    s=0
    for i in m.keys():
        for j in m[i].keys():
            s+=m[i][j]

    if s==0:
        s+=1
    print(ans_swaps+s-1)
    print(' '.join(ans))
