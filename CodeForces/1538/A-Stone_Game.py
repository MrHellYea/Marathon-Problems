t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    min_index = a.index(min(a))
    max_index = a.index(max(a))

    higher = max_index if max_index > min_index else min_index
    lower = min_index if max_index > min_index else max_index

    k1 = higher + 1
    k2 = len(a) - lower
    k3 = (lower + 1) + (len(a) - higher)

    options = [k1, k2, k3]

    print(min(options))
