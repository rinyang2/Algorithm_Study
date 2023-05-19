import sys
n = int(input())
a,b = map(int, input().split())

arr = [[] for _ in range(n+1)]

m = int(input())
for _ in range(m):
    x,y = map(int, sys.stdin.readline().split())
    arr[x].append(y)
    arr[y].append(x)

visited = [0] * (n+1)

def dfs(n):
    for i in arr[n]:
        if i != a and visited[i] == 0:
            visited[i] = visited[n]+1
            dfs(i)
dfs(a)

print(-1 if visited[b] == 0 else visited[b])