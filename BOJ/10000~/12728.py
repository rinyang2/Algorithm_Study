import sys

T = int(input())

mod = 1000

def matrix_mul(arr1, arr2):
    a = arr1[0] * arr2[0] + arr1[1] * arr2[2]
    b = arr1[0] * arr2[1] + arr1[1] * arr2[3]
    c = arr1[2] * arr2[0] + arr1[3] * arr2[2]
    d = arr1[2] * arr2[1] + arr1[3] * arr2[3]
    return [a%mod,b%mod,c%mod,d%mod]

def solution(n):
    ans = [1,0,0,1]
    temp = [3,5,1,3]

    while n:
        if n%2 == 1:
            ans = matrix_mul(ans, temp)
        temp = matrix_mul(temp, temp)
        n //=2
    return ans

#규칙성 찾아서 푸는 방법(3부터 100개 단위로 반복됨)
'''
arr = []
left = 3
right = 1
for i in range(101):
    temp = left
    left = (temp * 3 + right * 5)%1000
    right = (temp + right * 3)%1000
    arr.append(left)
'''
for test_case in range(1, T+1):
    n = int(sys.stdin.readline())
    ans = '000'+str(solution(n)[0] *2 -1)
    #ans2 = '000' + str(arr[1:][(n-3)%100] *2 -1)
    print("Case #{}: {}".format(test_case, ans[-3:]))
    #print("Case #{}: {}".format(test_case, '027' if n == 2 else ans2[-3:]))
    