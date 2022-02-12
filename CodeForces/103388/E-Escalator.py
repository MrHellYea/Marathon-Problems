left_to_right = []
right_to_left = []

for count, person in enumerate(range(int(input()))):
    t, d = map(int, input().split())

    if d == 0:
        if count == 0:
            direction = 0
            current = t
        else:
            left_to_right.append(t)
    else:
        if count == 0:
            direction = 1
            current = t
        else:
            right_to_left.append(t)

while len(left_to_right + right_to_left) > 0:
    if len(left_to_right) > 0 and direction == 0 and \
            current < left_to_right[0] <= current + 10:
        current = left_to_right[0]
        del left_to_right[0]
    elif len(right_to_left) > 0 and direction == 1 and \
            current < right_to_left[0] <= current + 10:
        current = right_to_left[0]
        del right_to_left[0]
    elif len(right_to_left) == 0 or (len(left_to_right) > 0 and
                                     left_to_right[0] < right_to_left[0]):
        if left_to_right[0] > current + 10:
            current = left_to_right[0]
        else:
            if direction == 1:
                current += 10
        direction = 0
        del left_to_right[0]
    elif len(left_to_right) == 0 or (len(right_to_left) > 0 and
                                     right_to_left[0] < left_to_right[0]):
        if right_to_left[0] > current + 10:
            current = right_to_left[0]
        else:
            if direction == 0:
                current += 10
        direction = 1
        del right_to_left[0]

print(current + 10)
