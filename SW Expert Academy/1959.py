T = int(input())

for tc in range(1,T+1):
    N,M = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    ans = -1e9

    short = A if len(A)<=len(B) else B

    long = B if short == A else A

    for i in range(len(long)-len(short)+1):
        temp = 0
        for j in range(len(short)):
            temp += long[j+i]*short[j]
        ans = max(ans, temp)
    print('#{} {}'.format(tc,ans))