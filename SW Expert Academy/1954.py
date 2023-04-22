T = int(input())

def snail(n):
    arr = [[0]*n for _ in range(n)]
    row, col = 0,-1
    temp = 1

    arr2 = sorted([n]+list(range(1,n))*2, reverse=True)

    up,down,left,right = False, False, False, True
    for i in arr2:
        for j in range(i):
            if right:
                col += 1
            elif left:
                col -= 1
            elif up:
                row -= 1
            elif down:
                row += 1   
            arr[row][col] = temp
            temp += 1       
        if right:
            right = False
            down = True
        elif down:
            down = False
            left = True
        elif left:
            left = False
            up = True
        elif up:
            up = False
            right = True
    return arr

for test_case in range(1, T+1):
    n = int(input())
    print('#{}'.format(test_case))
    ans = snail(n)
    for i in ans:
        print(*i)