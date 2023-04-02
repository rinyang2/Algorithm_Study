#unsolved
from itertools import combinations
import sys
N, K = map(int, input().split())
nessacary = 'antic'
alphabet = 'bdefghjklmopqrsuvwxyz'
ans = 0


def canread(s, taught):
    result = True
    for char in s:
        if char not in taught:
            if char not in nessacary:
                return False
    return result


if K<5:
    print(0)
else:
    cases = list(combinations(alphabet, K-5))
    arr = []
    for _ in range(N):
        arr.append(sys.stdin.readline().rstrip()[4:-4])

    for case in cases:
        temp = 0
        for s in arr:
            if canread(s, case):
                temp += 1
        ans = max(ans, temp)

    print(ans)