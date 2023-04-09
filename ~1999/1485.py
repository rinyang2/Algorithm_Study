import sys
def is_square(arr):
    v = [[arr[1][0] - arr[0][0], arr[1][1] - arr[0][1]], [arr[2][0] - arr[0][0], arr[2][1] - arr[0][1]], [arr[3][0] - arr[0][0], arr[3][1] - arr[0][1]]]
    v.sort(key = lambda x: length(x))
    if product(v[0], v[1]) == 0 and length(v[0]) == length(v[1]) and vec_add(v[0], v[1]) == v[2]:
        return True
    else:
        return False
def product(a,b):
    return a[0] * b[0] + a[1] * b[1]
def length(a):
    return a[0]**2 + a[1]**2
def vec_add(a,b):
    return [a[0]+b[0], a[1]+b[1]]

T = int(sys.stdin.readline())
for _ in range(T):
    arr = []
    for i in range(4):
        arr.append(list(map(int, sys.stdin.readline().split())))
    print(1 if is_square(arr) else 0)