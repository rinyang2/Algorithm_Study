N = int(input())

arr = [0]*10
for i in range(1,N+1):
    for j in str(i):
        arr[int(j)]+= 1
print(*arr)