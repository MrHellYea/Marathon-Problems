for q in range(int(input())):
    n = int(input())
    a = sorted(list(map(int, input().split())))

    area = a[0] * a[-1]
    for i in range(0, 4 * n, 2):
        if a[i] * a[-i - 1] != area or a[i] != a[i + 1]:
            print("NO")
            break
    else:
        print("YES")
