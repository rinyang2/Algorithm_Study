#Sieve of eratosthenes
def primeNumbers(n):
    arr = [True] * (n + 1)
    arr[1] = False
    for i in range(2, n + 1):
        if arr[i]:
            for j in range(i + i, n + 1, i):
                arr[j] = False
    return [i for i in range(2, n + 1) if arr[i]]

#이진수 변환
def binary(n):
    temp = ''
    while n:
        if n%2 == 0:
            temp += '0'
        else:
            temp += '1'
        n = n//2
    return temp

#거듭제곱 나머지
def powMod(base, index, mod):
    r = 1
    while index:
        if index & 1:
            r = (r*base) %mod
        base = (base**2) %mod
        index >>=1
    return r

#GCD
def gcd(a,b):
    if b == 0:
        return a
    return gcd(b, a%b)

#function that returns the area of a triangle with input of 3 dots
def t_Area(dot1, dot2, dot3):
    x,y = 0,1
    return abs(((dot2[x] - dot1[x])*(dot3[y]-dot1[y]) - (dot3[x]-dot1[x]) * (dot2[y] - dot1[y]))/2)

'''
n = int(input())
#이분탐색을 통한 n번째 제곱ㄴㄴ수 찾기
l,r = 0, 2000000000
while l < r-1:
    mid = (l+r) // 2
    if below_n(mid)<n:
        l = mid
    else:
        r = mid
print(r)
'''
