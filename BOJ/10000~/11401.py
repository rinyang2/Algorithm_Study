N,K = map(int, input().split())
mod = 1000000007
def powMod(base, index, mod):
    r = 1
    while index:
        if index & 1:
            r = (r*base) %mod
        base = (base**2) %mod
        index >>=1
    return r

arr = [1,1]
for i in range(2, N+1):
    arr.append((arr[i-1]*i) %mod)

print((arr[N] * powMod(arr[K]*arr[N-K], mod-2, mod))%mod)

