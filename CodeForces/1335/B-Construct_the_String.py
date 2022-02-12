for t in range(int(input())):
    n, a, b = map(int, input().split())

    string = []
    aux = 97
    for i in range(1, n + 1):
        string.append(chr(aux))
        aux = 97 if (i % b == 0) else aux + 1

    print("".join(string))
