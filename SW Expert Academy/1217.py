def pow(num, p):
    if p == 1:
        return num
    else:
        return num * pow(num, p-1)


for test_case in range(1, 11):
    T = int(input())
    n,m = map(int, input().split())
    print('#{} {}'.format(test_case,pow(n,m)))