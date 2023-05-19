import sys
def solution(n,m,maps):
    arr = [[] for _ in range(n*m)]
    
    for i in range(n):
        for j in range(m):
            try:
                if maps[i][j] == 1 and maps[i+1][j] == 1:
                    arr[i*m+j].append((i+1)*m+j)
                    arr[(i+1)*m+j].append(i*m+j)
            except:
                pass
            try:
                if maps[i][j] == 1 and maps[i][j+1] == 1:
                    arr[i*m+j].append(i*m+j+1)
                    arr[i*m+j+1].append(i*m+j)
            except:
                pass
    queue = [0]
    visited = [0]*(n*m)
    visited[0] = 1
    while queue:
        temp = queue.pop(0)
        for i in arr[temp]:
            if visited[i]==0:
                queue.append(i)
                visited[i] += visited[temp]+1
    return visited[-1] if visited[-1] != 0 else -1

N,M = map(int, input().split())
arr = []
for i in range(N):
    temp = []
    for char in sys.stdin.readline().rstrip():
        temp.append(int(char))
    arr.append(temp)
print(solution(N,M,arr))