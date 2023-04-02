arr = [0,1]
for i in range(1,1500000):
    arr.append((arr[i] + arr[i-1])%1000000)
print(arr[int(input())%1500000])