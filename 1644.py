def primeNumbers(n):
    arr = [True] * (n + 1)
    arr[1] = False
    for i in range(2, n + 1):
        if arr[i]:
            for j in range(i + i, n + 1, i):
                arr[j] = False
    return [i for i in range(2, n + 1) if arr[i]]
N = int(input())
p=primeNumbers(N)

#left pointer
left = 0
#right pointer
right = 0
#end index of Prime number list
end = len(p)
cnt = 0
while left < end and right < end:
    rangeSum = sum(p[left:right+1])
    if rangeSum == N:
        cnt += 1
        left += 1
    elif rangeSum > N:
        left += 1
    else:
        right += 1
print(cnt)
    
