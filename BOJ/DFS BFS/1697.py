N,K = map(int, input().split())
arr = [0] * 100001

queue = [N]
while queue:
    temp = queue.pop(0)
    if temp == K:
        print(arr[K])
        break
    for k in (temp+1, temp-1, temp*2):
        if 0 <= k <= 100000 and not arr[k]:
            queue.append(k)
            arr[k] = arr[temp]+1
