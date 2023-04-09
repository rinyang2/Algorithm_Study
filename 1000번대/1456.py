import math
import sys

"""
어떤 수가 소수의 N제곱(N ≥ 2) 꼴일 때, 그 수를 거의 소수라고 한다.
두 정수 A와 B가 주어지면, A보다 크거나 같고, B보다 작거나 같은 거의 소수가 몇 개인지 출력한다.

1 ≤ A ≤ B ≤ 10^14

Time limit = 2sec
Memory limit = 256MB
"""

a,b = map(int, sys.stdin.readline().split())
n = int(b**0.5)
m = int(n**0.5)
#Sieve of eratosthenes
arr = [True] * (n + 1)
arr[1] = False
for i in range(2, m + 1):
    if arr[i]:
        for j in range(i + i, n + 1, i):
            arr[j] = False
Sieve_of_eratosthenes = [i for i in range(2, n + 1) if arr[i]]

ans = 0
for i in Sieve_of_eratosthenes:
    temp = i
    i = i*i
    while i<=b:
        if i>=a:
            ans += 1
        i *= temp

print(ans)