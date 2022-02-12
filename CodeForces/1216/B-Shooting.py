n = int(input())
a = list(map(int, input().split()))

shots = 0
order = []
for count, can in enumerate(a):
    index = a.index(max(a))
    shots += a[index] * count + 1
    order.append(index + 1)
    a[index] = 0

print(shots)
print(*order)
