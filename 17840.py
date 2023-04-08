import sys

Q, M = map(int, sys.stdin.readline().split())

arr = [1,1]
for i in range(1000000):
    if arr[i] == 0 and arr[i+1] == 1:
        break
    arr.append((arr[i]+arr[i+1])%M)

arr.pop()

s = ''
for num in arr:
    for char in str(num):
        s += char

for _ in range(Q):
    print(s[(int(sys.stdin.readline())-1)  %len(s)])