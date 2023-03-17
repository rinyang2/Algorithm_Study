import sys
"""
151은 소수이면서 동시에 팰린드롬이기 때문에 소수인 팰린드롬이다. 
팰린드롬이란 앞으로 읽어나 뒤로 읽으나 같은 수를 말한다. 
예를 들어 1234는 앞으로 읽으면 1234지만, 뒤로 읽으면 4321이 되고 이 두 수가 다르기 때문에 팰린드롬이 아니다. 
두 정수 a, b가 주어졌을 때, a이상 b이하인 소수인 팰린드롬을 모두 구하는 프로그램을 작성하시오.
"""
#function to check if a number is pelindrome
def isPelindrome(n):
    if str(n) == str(n)[::-1]:
        return True
    else:
        return False
#function to check if a number is a prime number
def isPrime(n):
    if n == 1:
        return False
    for i in range(2, int(n**0.5)+1):
        if n%i == 0:
            return False
    return True
#function to calculate the next closest pelindrome number
def next_pelindrome(n):
    if len(str(n))==1:
        if n == 9:
            return 11
        else:
            return n+1
    str_n = str(n)
    left = int(str_n[:len(str_n)//2])
    if len(str_n)%2 != 0:
        middle = int(str_n[len(str_n)//2])
    #case where length is odd number
    try:
        if int(str(left)+str(middle)+str(left)[::-1]) > n:
            return int(str(left)+str(middle)+str(left)[::-1])
        else:
            if middle != 9:
                return int(str(left)+str(middle+1)+str(left)[::-1])
            #case where the center number is 9
            else:
                if len(str(int(str(left)+str(middle))+1)) == len(str(left)+str(middle)):
                    temp = int(str(left)+str(middle))+1
                    return int(str(temp)+(str(temp)[:-1])[::-1])
                else:
                    return n+2
    #case where length is even number
    except:
        if int(str(left)+str(left)[::-1]) > n:
           return int(str(left)+str(left)[::-1])
        else:
            if len(str(left+1)) == len(str(left)):
                return int(str(left+1)+str(left+1)[::-1])
            else:
                return int(str(left+1)[:-1]+str(left+1)[::-1])

a,b = map(int, sys.stdin.readline().split())

if not isPelindrome(a):
    a = next_pelindrome(a)

while a <= b:
    #since abcddcba is always divided by 11, and input is smaller than 10^8, pass
    if a> 10000000:
        break
    #if a pelindrome number has even length, it is always divided by 11 so pass
    if int(len(str(a)))%2 == 0:
        if a == 11:
            print(11)
        a = 10**len(str(a))
        a = next_pelindrome(a)
        continue
    if isPrime(a):
        print(a)
    a = next_pelindrome(a)
print(-1)