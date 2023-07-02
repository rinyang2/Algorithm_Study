def rotate_arr(arr):
    temp = []
    l = len(arr)
    for i in range(l):
        temp.append([arr[x][i] for x in range(l)][::-1])
    return temp
T = int(input())

def to_string(arr):
    temp = ''
    for i in arr:
        temp += str(i)
    return temp
for test_case in range(1, T+1):
    N = int(input())
    arr = []
    for _ in range(N):
        arr.append(list(map(int, input().split())))
    ans = []
    for _ in range(3):
        arr = rotate_arr(arr)
        ans.append(arr)
    print('#'+str(test_case))

    for i in range(N):
        for j in range(3):
            print(to_string(ans[j][i]), end = ' ')
        print()