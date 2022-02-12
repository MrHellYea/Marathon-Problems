from typing import List


def rearrange(s: List[str], t: str) -> List[int]:
    moves = []

    for count, element in enumerate(t):
        index = s.index(element)
        moves += range(count + 1, count + 1 + index)[::-1]
        s.pop(index)

    return moves


n = int(input())
s = input()
t = input()

if sorted(s) != sorted(t):
    print(-1)
else:
    moves = rearrange(list(s), t)

    print(len(moves))
    print(*moves)  # This line prints each element of the array individually
