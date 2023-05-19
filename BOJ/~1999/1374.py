"""
N개의 강의가 있다. 우리는 모든 강의의 시작하는 시간과 끝나는 시간을 알고 있다.
이때, 우리는 최대한 적은 수의 강의실을 사용하여 모든 강의가 이루어지게 하고 싶다.
물론, 한 강의실에서는 동시에 2개 이상의 강의를 진행할 수 없고, 
한 강의의 종료시간과 다른 강의의 시작시간이 겹치는 것은 상관없다. 
필요한 최소 강의실의 수를 출력하는 프로그램을 작성하시오.

N(1 ≤ N ≤ 100,000)

Time limit = 2sec
Memory limit = 128MB
"""

import sys
from heapq import heappop, heappush
N = int(sys.stdin.readline())
arr = []
for _ in range(N):
    arr.append(list(map(int, sys.stdin.readline().split())))
arr.sort(key = lambda x: x[1])
heap = []
ans = 0
for i in arr:
    while heap and heap[0] <= i[1]:
        heappop(heap)
    heappush(heap, i[2])
    ans = max(ans, len(heap))
print(ans)