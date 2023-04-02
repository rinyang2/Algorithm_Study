S = list(input())
T = list(input())

for i in range(len(T)- len(S)):
    if T[-1] == 'A':
        if T[0] == 'A':
            T.pop()
    else:
        T.pop()
        T = T[::-1]
print(1 if S == T else 0)
