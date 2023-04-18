T = int(input())

def right_row(s):
    cnt = 0
    index = 1e9
    for i in range(len(s)):
        if s[i] == 'O':
            cnt += 1
            index = i
    if cnt == 1:
        return index
    else:
        return 9

for test_case in range(1, T + 1):
    ans = [False] * 8
    arr = []
    for _ in range(8):
        arr.append(input())
    for s in arr:
        b = right_row(s)
        if b!= 9:
            ans[b] = True
        else:
            break
    if False in ans:
        print('#' + str(test_case) + ' '+ 'no')
    else:
        print('#' + str(test_case) + ' '+ 'yes')
