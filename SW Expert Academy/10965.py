def primeNumbers(n):
    arr = [True] * (n + 1)
    arr[1] = False
    for i in range(2, n + 1):
        if arr[i]:
            for j in range(i + i, n + 1, i):
                arr[j] = False
    return [i for i in range(2, n + 1) if arr[i]]
primeset = primeNumbers(3162)
def solution(n):
    if (n**0.5) %1 == 0:
        return 1
    else:
        ans = 1
        for i in primeset:
            b = False
            while n%i == 0:
                n//=i
                b = not b
            if b:
                ans *= i
            if n == 1 or i>n:
                break
        if n != 1:
            ans *= n
        return ans
T = int(input())
answer = []
for test_case in range(1, T + 1):
	answer.append("#{} {}".format(test_case, solution(int(input()))))
for s in answer:
    print(s)