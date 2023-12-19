T = int(input())
aa = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
for _ in range(T):
    a,b = map(int, input().split())
    ans = []
    for i in range(a-b,a+1):
        ans.append(i)
    for i in range(a-b-1, 0, -1):
        ans.append(i)
    print(*ans)