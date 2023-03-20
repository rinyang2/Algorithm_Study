import sys

N = int(sys.stdin.readline())

arr = list(map(int, sys.stdin.readline().split()))

if N == 1:
    print('A')
elif N == 2:
    if arr[0] == arr[1]:
        print(arr[0])
    else:
        print('A')
else:
    if arr[1]-arr[0] == 0:
        a = 0
    else:
        a = (arr[2] - arr[1]) / (arr[1]-arr[0])
    b = arr[1] - arr[0]*a
    if a%1 != 0:
        print('B')
    else:
        k = True
        for i in range(1,N):
            if arr[i] != arr[i-1]*int(a) + int(b):
                k = False
                break
        print(arr[N-1]*int(a)+int(b) if k else 'B')