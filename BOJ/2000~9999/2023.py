import sys

def isPrime(n):
    if n == 1:
        return False
    for i in range(2, int(n**0.5)+1):
        if n%i == 0:
            return False
    return True

N = int(sys.stdin.readline())

arr = [[2,3,5,7]]
for i in range(N-1):
    temp = []
    for num in arr[i]:
        for j in range(1,10,2):
            if isPrime(num*10+j):
                temp.append(num*10+j)
    arr.append(temp)
for i in arr[N-1]:
    print(i)
