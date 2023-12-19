import sys
T = int(sys.stdin.readline())
answer=[]
for _ in range(T):
    n= int(sys.stdin.readline())
    an = list(map(int, sys.stdin.readline().split()))
    bn = list(map(int, sys.stdin.readline().split()))
    arr = sorted([[an[i]+bn[i], i]for i in range(n)], reverse=True)
    #arr = sorted([sorted([an[i],bn[i]], reverse = True)+[i] for i in range(n)], reverse = True)
    #print(arr)
    ans = 0
    visited = [0]*n
    for i in range(n):
        if i%2 ==0:
            ans+=an[arr[i][1]]-1
        else:
            ans-=bn[arr[i][1]]-1
    answer.append(ans)
print(*answer,sep='\n')