t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    evens, odds = 0, 0
    for count, element in enumerate(a):
        if count % 2 != element % 2:
            if element % 2 == 0:
                evens += 1
            else:
                odds += 1

    if evens == odds:
        print(evens)
    else:
        print(-1)
