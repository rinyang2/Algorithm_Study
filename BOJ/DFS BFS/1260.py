import sys
N,M,V = map(int, input().split())

arr = [[] for _ in range(N+1)]

for _ in range(M):
    x,y = map(int, sys.stdin.readline().split())
    arr[x].append(y)
    arr[y].append(x)
for wer in arr:
    wer.sort()

visit = [False] * (N+1)

def dfs(n):
    visit[n] = True
    for i in arr[n]:
        if not visit[i]:
            print(i, end = ' ')
            dfs(i)
visited = [0] *(N+1)
def bfs(n):
    queue = [n]
    visited[n] = 1
    while queue:
        t = queue.pop(0)
        for k in arr[t]:
            if visited[k] == 0:
                print(k, end = ' ')
                queue.append(k)
                visited[k] = 1
print(V, end = ' ')
dfs(V)
print()
print(V, end = ' ')
bfs(V)