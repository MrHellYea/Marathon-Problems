n = int(input())
s = list(input())

changes = 0
for i in range(0, n, 2):
    if s[i] == s[i + 1]:
        changes += 1
        s[i:i + 2] = "ab"

print(changes)
print("".join(s))
