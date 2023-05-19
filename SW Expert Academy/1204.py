def mcn(arr):
    temp = []
    for i in range(101):
        temp.append([i,0])
    for i in arr:
        temp[i][1] += 1
    temp.sort(key = lambda x: x[0], reverse = True)
    temp.sort(key = lambda x: x[1], reverse = True)
    return temp[0][0]

T = int(input())

for test_case in range(1, T+1):
    k = input()
    arr = list(map(int, input().split()))
    print("#{} {}".format(test_case, mcn(arr)))