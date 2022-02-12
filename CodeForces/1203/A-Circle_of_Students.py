for q in range(int(input())):
    n = int(input())
    p = list(map(int, input().split()))

    for i in range(n - 1):
        if not (p[i + 1] == p[i] + 1 or p[i + 1] == 1):
            p = p[::-1]
            for j in range(n - 1):
                if not (p[j + 1] == p[j] + 1 or p[j + 1] == 1):
                    print("NO")
                    break
            else:
                print("YES")
            break
    else:
        print("YES")
