# (N/x)**x 의 최대값
# 미분 후 0이 되는 값 = e(2.71..)
# e에 가장 근접한 자연수 = 3

N = int(input())

if N<5:
    print(N)
else:
    a = N//3
    b = N%3
    if b == 0:
        print(3**a % 10007)
    elif b == 1:
        print(3**(a-1)*4 %10007)
    elif b == 2:
        print(3**a*2 % 10007)