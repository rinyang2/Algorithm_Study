#1474
import sys
N,M = map(int, sys.stdin.readline().split())
arr = []
for i in range(N):
    s = sys.stdin.readline().rstrip()
    M -= len(s)
    arr.append([s,i])
#기본 선 길이
line = M//(N-1)
#1추가 길이 선 개수
pluses = M%(N-1)

ans = arr[0][0]
#대문자로 시작하는 단어의 개수
arr = arr[1:]
arr.sort(reverse = True)
index = 0
for i in range(len(arr)):
    if i == len(arr)-1 and arr[i][0][0].islower():
        index = len(arr)
    if arr[i][0][0].isupper():
        index = i
        break
l,r = arr[:index], arr[index:]
l.sort(key=lambda x: x[1])
for word in l:
    if pluses > 0:
        word[0] = '_'*(line+1)+word[0]
        pluses -= 1
    else:
        word[0] = '_'*line+word[0]
r.sort(key = lambda x:x[1], reverse = True)

for word in r:
    if pluses > 0:
        word[0] = '_'*(line+1)+word[0]
        pluses -= 1
    else:
        word[0] = '_'*line+word[0]
arr = l+r

arr.sort(key = lambda x:x[1])

for word in arr:
    ans += word[0]
print(ans)