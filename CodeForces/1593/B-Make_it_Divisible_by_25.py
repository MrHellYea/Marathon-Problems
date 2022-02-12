import math


for t in range(int(input())):
    n = input()
    answer = math.inf

    for i in ("00", "25", "50", "75"):
        aux = 1

        for count, value in enumerate(n[::-1], 1):
            if value == i[aux]:
                aux -= 1

                if aux < 0:
                    answer = min(answer, count - 2)
                    break

    print(answer)
