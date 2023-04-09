import sys
"""
어떤 수 N이 주어졌을 때, N으로 시작하면서, N의 0이 아닌 모든 자리수로 나누어지는 떨어지는 수 중 가장 작은 수를 출력하는 프로그램을 작성하시오.
첫째 줄에 어떤 수 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.
Time limit = 2sec
Memory limit = 128MB
"""
N = int(sys.stdin.readline())
#use set to remove overlapping digit
numset = set()
for i in str(N):
    numset.add(int(i))
def gcd(a,b):
    if b == 0:
        return a
    return gcd(b, a%b)
def lcm(arr):
    temp = 1
    for i in arr:
        temp = int(i*temp/gcd(i,temp))
    return temp
#handle case of ZeroDivisionError
if 0 in numset:
    numset.remove(0)
divider = lcm(numset)

temp = 10
number = N
while True:
    if number % divider == 0:
        print(number)
        break
    number = int( str(N) + str(temp)[1:]  )
    temp += 1