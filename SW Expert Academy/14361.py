T = int(input())

def solution(n):
    l = len(str(n))
    temp = n
    while len(str(temp)) == l:
        temp += n
        if sorted(list(str(temp))) == sorted(list(str(n))):
            return True
    return False


for test_case in range(1, T + 1):
    print('#{} {}'.format(test_case, 'possible' if solution(int(input())) else 'impossible'))