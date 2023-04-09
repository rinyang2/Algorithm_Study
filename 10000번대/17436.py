import sys
from itertools import combinations

def mul(arr):
    res = 1
    for i in arr:
        res *= i
    return res

N,M = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
ans = 0
for i in range(1,N+1):
    for j in list(combinations(arr,i)):
        ans += (M // mul(j)) * ((-1)**(i+1))
print(ans)