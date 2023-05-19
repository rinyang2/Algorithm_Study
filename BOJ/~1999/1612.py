"""
For input N, print the length of the smallest number k
k is a number made with only digit '1'(ex: 1, 11, 111...)
0<N<1000000
Time limit = 2 sec
Memory limit = 128MB
"""

import sys
N = int(sys.stdin.readline())

if N%2 == 0 or N%5 == 0:
    print(-1)
else:
    temp = 1
    cnt = 1
    while 1:
        if temp % N == 0:
            print(cnt)
            break
        temp = (temp*10+1)%N
        cnt+=1