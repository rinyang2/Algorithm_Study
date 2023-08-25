t=int(input())

for _ in range(t):
    s = input()
    n = len(s)
    if(s == '()'):
        print('NO')
        continue
    print('YES')
    if(len(set(list(s)))==1):
        print('()'*n)
    else:
        if list(s) == sorted(list(s)):
            print('()' * n)
        else:
            print('('*n + ')'*n)