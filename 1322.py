import sys

def binary(n):
    temp = ''
    while n:
        if n%2 == 0:
            temp += '0'
        else:
            temp += '1'
        n = n//2
    return temp

def reverse_binary(n):
    temp = ''
    for num in n:
        if num == '0':
            temp += '1'
        elif num == '1':
            temp += '0'
    return temp
X,K = map(int, sys.stdin.readline().split())

X_bin = binary(X)
K_bin = binary(K)
zero = []

ans_arr = [0] * 64

for i in range(len(X_bin)):
    if X_bin[i] == '1':
        ans_arr[i] = 1

for element in K_bin:
    for i in range(64):
        if ans_arr[i] == 0:
            ans_arr[i] = element
            break
ans = 0

for i in range(64):
    if ans_arr[i] == 1:
        continue
    ans += int(ans_arr[i]) * 2**i
print(ans)