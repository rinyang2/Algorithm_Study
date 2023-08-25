t = int(input())

for _ in range(t):
    m,k,a1,ak = map(int, input().split())
    #m%k = 1짜리 동전 필요 개수
    #m/k = k짜리 동전 필요 개수
    #a1/k = 1짜리 동전으로 k동전 대체가능
    cnt = 0
    a1 -= m%k
    m -= m%k

    if a1<0:
        cnt -= a1
    else:
        ak += a1//k

    ak -= m//k
    if ak<0:
        cnt-= ak
    print(cnt)