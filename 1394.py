charset = input()
passwd = input()

def powMod(base, index, mod):
    r = 1
    while index:
        if index & 1:
            r = (r*base) %mod
        base = (base**2) %mod
        index >>=1
    return r

ans = 0
charset_len = len(charset)
dic = {}
for i in range(charset_len):
    dic[charset[i]] = i
passwd_len = len(passwd)

for i in range(1, passwd_len):
    ans += powMod(charset_len, i, 900528)
for char in passwd:
    passwd_len -= 1
    ans += dic[char] *powMod(charset_len, passwd_len, 900528)
ans += 1
ans %= 900528
print(ans)