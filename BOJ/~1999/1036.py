import sys

#36진수에 대응하는 알파벳의 10진수값을 담은 딕셔너리
alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
dic = {}
dic_reversed = {}
#어떤 숫자가 몇번 세어졌는지 담는 리스트
count = []
for i in range(10):
    count.append([str(i),0])
    dic[str(i)] = i
for i in range(26):
    count.append([alphabet[i],0])
    dic[alphabet[i]] = i+10
    dic_reversed[i+10] = alphabet[i]
#36진수를 10진수로 변환하는 함수
def to_int_36(s):
    ans = 0
    s = s[::-1]
    temp = 1
    for c in range(len(s)):
        try:
            ans += int(s[c])*temp
        except:
            ans += dic[s[c]]*temp
        temp *=36
    return ans
#10진수를 36진수로 변환하는 함수
def to_36_int(n):
    #이 부분 없어서 2번 틀림 ㅅㅂ(결과가 0인 경우에 대한 처리)
    if n == 0:
        return '0'
    result = ''
    while n:
        n, mod = divmod(n, 36)
        if mod<10:
            result += str(mod)
        else:
            result += dic_reversed[mod]
    return result [::-1]

#N 입력받음
N = int(sys.stdin.readline())

#36진수 N개만큼 입력받음
arr = []
for i in range(N):
    arr.append(sys.stdin.readline().rstrip())

#K 입력받음
K = int(sys.stdin.readline())

#모든 입력받은 36진수에 대해
for num in arr:
    temp = 1
    #어떤 숫자가 몇번 있는지 count에 저장함
    for c in num[::-1]:
        count[dic[c]][1] += temp
        temp *= 36

#쓰인 횟수 * Z와의 차이가 큰 순서대로 정렬
count.sort(key = lambda x: x[1] * (35-dic[x[0]]), reverse = True)

#정렬한 순서대로 K개의 숫자를 Z로 치환
for i in range(K):
    count[i][0] = 'Z'

ans = 0
#치환이 완료된 count리스트에서 숫자*쓰인 횟수만큼 ans에 더한 다음
for i in count:
    ans += dic[i[0]] * i[1]
#36진수로 변환하여 출력함
print(to_36_int(ans))