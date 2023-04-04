n = int(input())
a = list(map(int, input().split()))
t = int(input())
result = 0

for i in range(n):
    for j in range(i):
        if a[i] <= a[j] + t * 2 and a[i] >= a[j] - t * 2:
            result += 1

print(result / 4.0)
