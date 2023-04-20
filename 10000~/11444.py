import sys

T = int(input())

mod = 1000000007

def matrix_mul(arr1, arr2):
    a = arr1[0] * arr2[0] + arr1[1] * arr2[2]
    b = arr1[0] * arr2[1] + arr1[1] * arr2[3]
    c = arr1[2] * arr2[0] + arr1[3] * arr2[2]
    d = arr1[2] * arr2[1] + arr1[3] * arr2[3]
    return [a%mod,b%mod,c%mod,d%mod]

def solution(n):
    ans = [1,1,1,0]
    temp = [1,1,1,0]

    while n:
        if n%2 == 1:
            ans = matrix_mul(ans, temp)
        temp = matrix_mul(temp, temp)
        n //=2
    return ans

print(solution(T)[-1])