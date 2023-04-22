def translate(n, b):
    if n == 0:
        return 0
    s = ''
    if b>1:
        temp = abs(n)
        while temp:
            s += str(temp%b)
            temp //= b
        if n<0:
            s += '-'
        return s[::-1]
    elif b<-1:
        while n:
            k =  n%b<0
            s+=str(n%b - (b if k else 0))
            n = n//b + (1 if k else 0)
        return s[::-1]

x,b = map(int, input().split())
#a
print(translate(x,b))