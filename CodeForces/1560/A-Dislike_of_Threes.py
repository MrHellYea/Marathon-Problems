from typing import List


def create_array(length: int = 1000) -> List[int]:
    array = []

    num = 1
    while len(array) < length:
        if not (num % 3 == 0 or str(num)[-1] == '3'):
            array.append(num)
        num += 1

    return array


def main():
    array = create_array()
    t = int(input())

    for _ in range(t):
        k = int(input())
        print(array[k - 1])


if __name__ == "__main__":
    main()
