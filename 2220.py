n = int(input())
a = [0] * (n + 1)

for i in range(1, n):
    j = i
    while j > 1:
        a[j] = a[j//2]
        j //= 2
    a[1] = i+1

a[n] = 1

for i in range(1, n+1):
    print(a[i], end=' ')
