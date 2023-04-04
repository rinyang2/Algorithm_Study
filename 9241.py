original = input()
infected = input()

temp = 0
while temp<len(original) and temp<len(infected) and original[temp] == infected[temp]:
    temp += 1
original = original[temp:][::-1]
infected = infected[temp:][::-1]
temp = 0
while temp<len(original) and temp<len(infected) and original[temp] == infected[temp]:
    temp += 1
infected = infected[temp:]
print(len(infected))