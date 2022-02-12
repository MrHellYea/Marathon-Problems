n = int(input())
a = sorted(list(map(int, input().split())))

highest = 0
answer = 0
for element in a:
    if element - 1 != 0 and element - 1 > highest:
        highest = element - 1
        answer += 1
    elif element > highest:
        highest = element
        answer += 1
    elif element + 1 > highest:
        highest = element + 1
        answer += 1
print(answer)
