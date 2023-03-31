from collections import Counter

def is_antipelindrome(s):
    for i in range(len(s)//2):
        print(s[i], s[-1-i])
        if s[i] == s[-1-i]:
            return False
    return True

def sort_string(s):
    res = ''
    arr = list(s)
    arr.sort()
    for char in arr:
        res += char
    return res

def solvable(s):
    return (len(s)+1)//2 >= max(list({v: k for k,v in dict(Counter(list(s))).items() }))

def swap(s, a, b):
    return s[:a] + s[b] + s[a+1:b] + s[a] + s[b+1:]


s = input()
l = len(s)
if solvable(s):
    s = sort_string(s)
    for i in range((l+1)//2 , l):
        if s[i] == s[l-i-1]:
            for j in range(i, l):
                if s[j] != s[i]:
                    s = swap(s, i, j)
                    break
    print(s)
else:
    print(-1)