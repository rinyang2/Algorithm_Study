def primeNumbers(n):
    arr = [True] * (n + 1)
    arr[1] = False
    for i in range(2, n + 1):
        if arr[i]:
            for j in range(i + i, n + 1, i):
                arr[j] = False
    return [i for i in range(2, n + 1) if arr[i]]


#n 이하 제곱ㄴㄴ수의 개수를 구하는 함수
#포함배제원리 이용
def below_n(n):
    sqrtprimes = primeNumbers(int(n**0.5))
    ans = 0
    l = len(sqrtprimes)
    for i in range(l):
        ans += n//(sqrtprimes[i]**2)
    if l<2:
        return n-ans

    for i in range(l):
        if (sqrtprimes[i]**2) * (sqrtprimes[i+1]**2) > n:
            break
        for j in range(i+1,l):
            if (sqrtprimes[i]**2) * (sqrtprimes[j]**2) > n:
                break
            ans -= n//((sqrtprimes[i]**2) * (sqrtprimes[j]**2))
    if l<3:
        return n-ans

    for i in range(l):
        if (sqrtprimes[i]**2) * (sqrtprimes[i+1]**2) * (sqrtprimes[i+2]**2) > n:
            break
        for j in range(i+1,l):
            if (sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[j+1]**2) > n:
                break
            for k in range(j+1, l):
                if (sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[k]**2) > n:
                    break
                ans += n//((sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[k]**2) )
    if l<4:
        return n-ans
    
    for i in range(l):
        if (sqrtprimes[i]**2) * (sqrtprimes[i+1]**2) * (sqrtprimes[i+2]**2) * (sqrtprimes[i+3]**2) > n:
            break
        for j in range(i+1,l):
            if (sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[j+1]**2) * (sqrtprimes[j+2]**2) > n:
                break
            for k in range(j+1, l):
                if (sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[k]**2) * (sqrtprimes[k+1]**2) > n:
                    break
                for x in range(k+1,l):
                    if (sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[k]**2) * (sqrtprimes[x]**2) > n:
                        break
                    ans -= n//((sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[k]**2) * (sqrtprimes[x]**2) )
    if l<5:
        return n-ans
    for i in range(l):
        if (sqrtprimes[i]**2) * (sqrtprimes[i+1]**2) * (sqrtprimes[i+2]**2) * (sqrtprimes[i+3]**2) * (sqrtprimes[i+4]**2) > n:
            break
        for j in range(i+1,l):
            if (sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[j+1]**2) * (sqrtprimes[j+2]**2) * (sqrtprimes[j+3]**2) > n:
                break
            for k in range(j+1, l):
                if (sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[k]**2) * (sqrtprimes[k+1]**2) * (sqrtprimes[k+2]**2) > n:
                    break
                for x in range(k+1,l):
                    if (sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[k]**2) * (sqrtprimes[x]**2) * (sqrtprimes[x+1]**2) > n:
                        break
                    for y in range(x+1,l):
                        if (sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[k]**2) * (sqrtprimes[x]**2) * (sqrtprimes[y]**2) > n:
                            break
                        ans += n//((sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[k]**2) * (sqrtprimes[x]**2) * (sqrtprimes[y]**2) )
    if l<6:
        return n-ans

    for i in range(l):
        if (sqrtprimes[i]**2) * (sqrtprimes[i+1]**2) * (sqrtprimes[i+2]**2) * (sqrtprimes[i+3]**2) * (sqrtprimes[i+4]**2) * (sqrtprimes[i+5]**2) > n:
            break
        for j in range(i+1,l):
            if (sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[j+1]**2) * (sqrtprimes[j+2]**2) * (sqrtprimes[j+3]**2) * (sqrtprimes[j+4]**2) > n:
                break
            for k in range(j+1, l):
                if (sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[k]**2) * (sqrtprimes[k+1]**2) * (sqrtprimes[k+2]**2) * (sqrtprimes[k+3]**2) > n:
                    break
                for x in range(k+1,l):
                    if (sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[k]**2) * (sqrtprimes[x]**2) * (sqrtprimes[x+1]**2) * (sqrtprimes[x+2]**2) > n:
                        break
                    for y in range(x+1,l):
                        if (sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[k]**2) * (sqrtprimes[x]**2) * (sqrtprimes[y]**2) * (sqrtprimes[y+1]**2) > n:
                            break
                        for z in range(y+1,l):
                            if (sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[k]**2) * (sqrtprimes[x]**2) * (sqrtprimes[y]**2) * (sqrtprimes[z]**2) > n:
                                break    
                            ans -= n//((sqrtprimes[i]**2) * (sqrtprimes[j]**2) * (sqrtprimes[k]**2) * (sqrtprimes[x]**2) * (sqrtprimes[y]**2) * (sqrtprimes[z]**2) )
    return n-ans

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