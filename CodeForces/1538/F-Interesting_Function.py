def contagem(L, R):
    if R == 0:
        return 0
    else:
        return (R - L) + contagem(L // 10, R // 10)


t = int(input())

for _ in range(t):
    l, r = list(map(int, input().split()))

    print(contagem(l, r))
