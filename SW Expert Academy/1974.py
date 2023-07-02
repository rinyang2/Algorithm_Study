T = int(input())

for tc in range(1,T+1):
    arr = []
    temp = []
    #데이터 입력 및 가로 확인
    for _ in range(9):
        x = list(map(int, input().split()))
        arr.append(x)
        temp.append(len(set(x)))
    #세로 확인
    for i in range(9):
        x = [arr[x][i] for x in range(9)]
        temp.append(len(set(x)))
    #부분정사각형 확인
    for i in [0,3,6]:
        for j in [0,3,6]:
            sq = []
            for k in range(3):
                sq += arr[i+k][j:j+3]
            temp.append(len(set(sq)))
    print("#{} {}".format(tc, 1 if len(set(temp))== 1 else 0))