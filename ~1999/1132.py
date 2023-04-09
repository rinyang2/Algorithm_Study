import sys
N = int(sys.stdin.readline())
alphabet = 'ABCDEFGHIJ'
dic = {}
NOTZERO=''
for i in range(10):
    dic[alphabet[i]] = 0
for _ in range(N):
    s = sys.stdin.readline().rstrip()
    NOTZERO += s[0]
    l = len(s)
    for i in range(len(s)):
        dic[s[i]] += 10**(l-1)
        l -=1
arr = []
for i in dic:
    arr.append([dic[i],i])
arr.sort()
for i in range(10):
    if arr[i][1] not in NOTZERO:
        arr[i].append('ZERO')
        break

for c in arr:
    if len(c) == 3:
        arr.remove(c)
        break
ans= 0
for i in range(9):
    ans += arr[i][0] * (i+1)
print(ans)