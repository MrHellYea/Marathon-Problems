for t in range(int(input())):
    a, b, c = map(int, input().split())

    a1 = max(max(b, c) - a + 1, 0)
    b1 = max(max(a, c) - b + 1, 0)
    c1 = max(max(a, b) - c + 1, 0)

    print(a1, b1, c1)
