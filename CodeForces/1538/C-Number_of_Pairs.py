t = int(input())
for _ in range(t):
    n, l, r = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()

    res = 0
    i, j = 0, 0
    while i < n:
        n -= 1
        while i < n and a[i] + a[n] < l:
            i += 1
        while j < n and a[j] + a[n] <= r:
            j += 1

        res += min(j, n) - i

    print(res)
