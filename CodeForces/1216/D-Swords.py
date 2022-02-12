from math import gcd

n = int(input())
a = list(map(int, input().split()))

highest = max(a)

y, z = 0, 0
for i in a:
    z = gcd(z, highest - i)

for i in a:
    y += (highest - i) // z

print(y, z)
