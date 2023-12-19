from collections import Counter
t = int(input())  
for _ in range(t):
    n = int(input()) 
    arr = list(map(int, input().split()))
    x = Counter(arr)
    y = [i for i in x if x[i]>1]
    if len(y)<2:
        print(-1)
        continue
    q,p = y[0],y[1]
    a,b = True, True
    ans = []
    for asd in arr:
        if asd==q:
            if a:
                ans.append(1)
                a = False
            else:
                ans.append(2)
        elif asd == p:
            if b:
                ans.append(1)
                b = False
            else:
                ans.append(3)
        else:
            ans.append(3)
    print(*ans)