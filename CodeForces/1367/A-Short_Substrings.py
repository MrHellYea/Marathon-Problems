t = int(input())

for _ in range(t):
    string = input()

    print(f"{string[::2]}{string[-1]}")
