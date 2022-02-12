n, m = map(int, input().split())

segment = [i for i in range(1, m + 1)]
for _ in range(n):
    l, r = map(int, input().split())

    segment = [i for i in segment if i not in list(range(l, r + 1))]

print(len(segment))
print(*segment)
