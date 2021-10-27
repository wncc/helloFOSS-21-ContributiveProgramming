import sys
input=sys.stdin.readline

t=int(input())

for _ in range(t):
    T,n=map(int,input().split())
    x=[int(i) for i in input().split()]
    y=[int(i) for i in input().split()]

    dp=[[0,[]] for i in range(T+1)]

    start=min(x)

    for i in range(n):
        for j in range(start,T+1):
            if x[i]<=j:
                if i not in dp[j-x[i]][1] and dp[j-x[i]][0]+y[i]>dp[j][0]: #To ensure we aren't counting the same chapter again
                    dp[j][0]=dp[j-x[i]][0]+y[i]
                    dp[j][1].append(i)

    print(dp[T][0])
