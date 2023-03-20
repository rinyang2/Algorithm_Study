N = int(input())

#Sieve of eratosthenes
def primeNumbers(n):
    arr = [True] * (n + 1)
    arr[1] = False
    for i in range(2, n + 1):
        if arr[i]:
            for j in range(i + i, n + 1, i):
                arr[j] = False
    return [i for i in range(2, n + 1) if arr[i]]

def goldbach(n):
    arr = primeNumbers(n)
    if n%2 == 0:
        for i in arr:
            if n-i-4 in arr:
                return [2, 2, i, n-i-4]
                break
    else:
        for i in arr:
                return [2, 3, i, n-i-5]
if N<8:
    print(-1)
else:
    for i in sorted(goldbach(N)):
        print(i, end = ' ')