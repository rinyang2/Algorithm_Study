T = int(input())

def pxmax(arr,N, M, x, y):
    center = arr[x][y]
    ver,diag = 0,0
    for i in range(1,M):
        if x-i>=0:
            ver += arr[x-i][y]
            if y-i>=0:
                diag += arr[x-i][y-i]
            if y+i <N:
                diag += arr[x-i][y+i]
        if x+i <N:
            ver += arr[x+i][y]
            if y-i>=0:
                diag += arr[x+i][y-i]
            if y+i <N:
                diag += arr[x+i][y+i]
        if y-i>=0:
            ver += arr[x][y-i]
        if y+i <N:
            ver += arr[x][y+i]
        
    return center+max(ver,diag)


for test_case in range(1,T+1):
    N,M = map(int, input().split())
    ans = 0
    arr=[]
    for _ in range(N):
        arr.append(list(map(int, input().split())))
    for i in range(N):
        for j in range(N):
            ans = max(ans, pxmax(arr,N,M,i,j))
    print("#{} {}".format(test_case, ans))
