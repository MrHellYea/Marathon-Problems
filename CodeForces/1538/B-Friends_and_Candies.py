t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    average = sum(a) / len(a)

    if average % 1 != 0:
        print(-1)
        continue

    print(sum(i > average for i in a))
