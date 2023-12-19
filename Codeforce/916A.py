import sys
T = int(input())
aa = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
for _ in range(T):
    dic = {}
    ans = {}
    for i in range(26):
        dic[aa[i]] = i+1
        ans [aa[i]]=0

    N = int(input())
    s = input()
    for a in s:
        ans[a]+=1
    cnt = 0
    for i in aa:
        if ans[i]>0 and ans[i]>=dic[i]:
            cnt+=1
    print(cnt)
    