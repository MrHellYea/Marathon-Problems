def main():
    t = int(input())

    for _ in range(t):
        a, b, c = [int(n) for n in input().split()]

        gap = abs(a - b) - 1
        people = gap * 2 + 2

        if gap == 0 or max(a, b, c) > people:
            print(-1)
        else:
            answer = (c + gap + 1) % people
            if answer == 0:
                answer = people
            print(answer)


if __name__ == "__main__":
    main()
