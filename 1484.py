"""
for input G, print all possoble cases of a where
a^2 - b^2 = G, (a, b is natural number)
"""

import sys
G = int(sys.stdin.readline())
arr = []
for i in range(1,int(G**0.5)+1):
    if G%i == 0:
        arr.append([i,int(G/i)])
Has_answer = False

for i in arr[::-1]:
    if sum(i)%2 == 0 and i[0]!=i[1]:
        print(int(sum(i)/2))
        Has_answer = True
if not Has_answer:
    print(-1)