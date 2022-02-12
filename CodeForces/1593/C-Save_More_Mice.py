for t in range(int(input())):
    n, k = map(int, input().split())
    mice = sorted(list(map(int, input().split())))[::-1]
    cat, answer = 0, 0

    for mouse in mice:
        if cat >= mouse:
            continue
        cat += n - mouse
        answer += 1

    print(answer)
