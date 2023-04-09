def squarePrime(min,max):
    size = max-min+1
    arr = [True] * (size)
    for i in range(2, int(max**0.5)+1):
        square = i**2
        d = square - min%square if min%square!=0 else 0
        for j in range(d, size, square):
            if arr[j]:
                arr[j] = False
    
    return len([min+i for i in range(size) if arr[i]])

min,max = map(int, input().split())
print(squarePrime(min,max))