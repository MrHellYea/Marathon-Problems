for t in range(int(input())):
    n = int(input())
    dict_a = {}

    for element in list(map(int, input().split())):
        if dict_a.get(element) is None:
            dict_a[element] = 0
        dict_a[element] += 1

    different = len(dict_a.keys()) - 1
    equal = max(dict_a.values())
    if equal - different >= 2:
        different += 1
    print(min(different, equal))
