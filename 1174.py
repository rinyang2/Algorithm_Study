"""
음이 아닌 정수를 십진법으로 표기했을 때, 왼쪽에서부터 자리수가 감소할 때, 그 수를 줄어드는 수라고 한다. 
예를 들어, 321와 950은 줄어드는 수이고, 322와 958은 아니다.
N번째로 작은 줄어드는 수를 출력하는 프로그램을 작성하시오. 
만약 그러한 수가 없을 때는 -1을 출력한다. 
가장 작은 줄어드는 수가 1번째 작은 줄어드는 수이다.
"""

import sys
from itertools import combinations
num = '9876543210'
arr = []
for i in range(1,11):
    temp = list(combinations(list(num),i))
    for j in temp:
        s = ''
        for k in j:
            s += k
        arr.append(int(s))
arr.sort()
N = int(sys.stdin.readline())
try:
    print(arr[N-1])
except:
    print(-1)