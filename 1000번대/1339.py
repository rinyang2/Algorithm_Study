N = int(input())
alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
arr = []
dic = {}
for i in range(26):
    dic[alphabet[i]] = i
    arr.append([alphabet[i],0])
for _ in range(N):
    s = input()
    multiplier = 1
    for c in s[::-1]:
        arr[dic[c]][1] += multiplier
        multiplier *= 10
arr.sort(key = lambda x: x[1], reverse=True)
ans = 0
temp = 9
t = 0
while temp:
    ans += arr[t][1]*temp
    temp -= 1
    t += 1
print(ans)