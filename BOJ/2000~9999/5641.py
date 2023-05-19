def primeNumbers(n):
    arr = [True] * (n + 1)
    arr[1] = False
    for i in range(2, n + 1):
        if arr[i]:
            for j in range(i + i, n + 1, i):
                arr[j] = False
    return [i for i in range(2, n + 1) if arr[i]]
N = int(input())
p=primeNumbers(N)

print(p)