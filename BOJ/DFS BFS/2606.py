#2606 - DFS

#number of computers
N = int(input())

#number of inputs
M = int(input())


arr = [[] for x in range(N+1)]
for i in range(M):
    a,b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)

#List for checking if visited
ans = [0] * (N+1)    

#solution using DFS algorityhm
def sol(n):
    ans[n] = 1
    for i in arr[n]:
        if ans[i] == 0:
            sol(i)

sol(1)
    
print(sum(ans)-1)