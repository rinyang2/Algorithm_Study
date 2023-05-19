import sys
from itertools import combinations
ans = []
t = int(input())
def distance(a,b):
    return abs(a[0]-b[0])+ abs(a[1]-b[1])
for test_case in range(t):
    n = int(input())
    arr = []
    node = [[] for _ in range (n+2)]

    for i in range(n+2):
        x,y = map(int, sys.stdin.readline().split())
        arr.append([x,y])

    for case in list(combinations(arr,2)):
        if distance(case[0],case[1]) <= 1000:
            node[arr.index(case[0])].append(arr.index(case[1]))
            node[arr.index(case[1])].append(arr.index(case[0]))
    visited = [0] * (n+2)
    queue = [0]
    while queue:
        temp = queue.pop(0)
        if temp == n+2:
            break
        for k in node[temp]:
            if visited[k] == 0:
                queue.append(k)
                visited [k] = visited[temp]+1
    print('happy' if visited[-1] else 'sad')
