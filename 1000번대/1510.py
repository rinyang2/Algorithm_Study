#UNSOLVED

from itertools import combinations
from collections import Counter

def distance(a,b):
    return ((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2)**0.5
def is_osceles(arr):
    a = arr[0]
    b = arr[1]
    c = arr[2]
    ab = distance(a,b)
    bc = distance(b,c)
    ca = distance(c,a)
    temp = [ab,bc,ca]
    temp.sort()
    if temp[0] == temp [1] or temp[1] == temp[2]:
        if temp[0]+temp[1] == temp[2]:
            return False
        else:
            return True
    else:
        return False
def isosceles(n,m):
    arr = []
    for i in range(n):
        for j in range(m):
            arr.append([i,j])

    comb = list(combinations(arr, 3))

    cnt = 0
    for i in comb:
        if is_osceles(i):
            cnt += 1
    return cnt


while(True):
    N,M = map(int, input().split())
    print(isosceles(N,M))
