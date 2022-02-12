from math import ceil, sqrt
from typing import Tuple


def simulate(num: int) -> Tuple[int, int]:
    i = 1
    j = 1

    j = ceil(sqrt(num))
    current = (j - 1) ** 2

    if current + j > num:
        i = num - current
    elif current + j < num:
        current += j
        i = j
        j -= num - current
    else:
        i = j

    return (i, j)


def main():
    t = int(input())

    for _ in range(t):
        k = int(input())
        i, j = simulate(k)
        print(i, j)


if __name__ == "__main__":
    main()
