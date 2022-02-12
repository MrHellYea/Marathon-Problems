for _ in range(int(input())):
    n, k = map(int, input().split())
    string = input()

    consec_zeroes, answer = 0, 0
    if string[0] == "0" and ("1" not in string[0:k + 1]):
        string = f"1{string[1:]}"
        answer += 1

    for count, char in enumerate(string):
        consec_zeroes += 1

        if char == "1":
            consec_zeroes = 0

        if (consec_zeroes > k) and ("1" not in string[count:count + k + 1]):
            answer += 1
            consec_zeroes = 0

    print(answer)
