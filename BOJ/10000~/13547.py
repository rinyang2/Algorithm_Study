# 백준에서 python3으로 채점시 시간초과남
# 동일 알고리즘 c++로 정답

import sys
# 첫째 줄에 수열의 크기 N이 주어진다
n = int(sys.stdin.readline())
# 둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 1,000,000)
arr = list(map(int, sys.stdin.readline().split()))
# 셋째 줄에는 쿼리의 개수 M (1 ≤ M ≤ 100,000)이 주어진다.
m = int(sys.stdin.readline())
# 넷째 줄부터 M개의 줄에는 쿼리 i, j가 한 줄에 하나씩 주어진다. (1 ≤ i ≤ j ≤ N)
queries = []
for _ in range(m):
    queries.append(list(map(int, sys.stdin.readline().split())))

# sqrt(n) 크기로 분할하여 mo's algorithm 수행
sq = int(n ** 0.5)
# 왼쪽 좌표 / sq 기준 정렬 후 동일값에 대해 오른쪽 좌표 기준 정렬
queries.sort(key=lambda x: (x[0] // sq, x[1]))

# 첫 번째 쿼리는 bruteforce 계산함
DAT = [0] * 1000001
for i in range(queries[0][0] - 1, queries[0][1]):
    DAT[arr[i]] += 1

cnt = 0
for i in range(1000001):
    if DAT[i] > 0:
        cnt += 1

# 투포인터를 이용해 다음 쿼리 수행
lp = queries[0][0]
rp = queries[0][1]
print(cnt)
for i in range(1, m):
    l = queries[i][0] - 1
    r = queries[i][1] - 1
    while lp < l:
        lp += 1
        DAT[arr[lp]] += 1
        if DAT[arr[lp]] == 1:
            cnt += 1

    while lp > l:
        lp -= 1
        DAT[arr[lp]] -= 1
        if DAT[arr[lp]] == 0:
            cnt -= 1

    while rp < r:
        rp += 1
        DAT[arr[rp]] += 1
        if DAT[arr[rp]] == 1:
            cnt += 1

    while rp > r:
        rp -= 1
        DAT[arr[rp]] -= 1
        if DAT[arr[rp]] == 0:
            cnt -= 1
    print(cnt)