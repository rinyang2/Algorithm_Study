T = int(input())

def min_ball(s):
    cnt = 0
    l = len(s)
    for i in range(l):
        if s[i] == '(':
            cnt += 1
        elif s[i] == ')':
            if s[i-1] == '|':
                cnt += 1
    return cnt

for test_case in range(1, T + 1):
    print('#{} {}'.format(test_case, min_ball(input())))