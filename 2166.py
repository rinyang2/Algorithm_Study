import sys
N = int(sys.stdin.readline())
arr = []
for i in range(N):
    arr.append(list(map(int, sys.stdin.readline().split())))
x1,y1 = arr[0][0], arr[0][1]
ans = 0
for i in range(1,len(arr)-1):
    x2, y2 = arr[i][0], arr[i][1]
    x3, y3 = arr[i+1][0], arr[i+1][1]

    ans += (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1)
print(round(abs(ans/2), 1))