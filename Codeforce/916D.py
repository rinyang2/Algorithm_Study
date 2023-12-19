import sys
T = int(sys.stdin.readline())
for _ in range(T):
    n= int(sys.stdin.readline())
    an = list(map(int, sys.stdin.readline().split()))
    bn = list(map(int, sys.stdin.readline().split()))
    cn = list(map(int, sys.stdin.readline().split()))
    an = sorted([[an[i],i] for i in range(n)], reverse=True)[:3]
    bn = sorted([[bn[i],i] for i in range(n)], reverse=True)[:3]
    cn = sorted([[cn[i],i] for i in range(n)], reverse=True)[:3]

    ans = 0
    for i in range(3):
        for j in range(3):
            for k in range(3):
                if an[i][1]!=bn[j][1] and an[i][1] != cn[k][1] and bn[j][1] !=cn[k][1]:
                    ans = max(ans, an[i][0]+bn[j][0]+cn[k][0])
    print(ans)