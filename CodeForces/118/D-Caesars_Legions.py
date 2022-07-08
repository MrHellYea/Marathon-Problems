dp = [[[[0 for _ in range(11)] for _ in range(11)] for _ in range(101)] for _ in range(101)]
n1, n2, k1, k2 = map(int, input().split())

for i in range(n1 + 1):
    for j in range(n2 + 1):
        for k in range(k1 + 1):
            for l in range(k2 + 1):
                if not i + j:
                    answer = 1
                else:
                    answer = 0
                    if i and k:
                        answer += dp[i - 1][j][k - 1][k2] % 1E8
                    if j and l:
                        answer += dp[i][j - 1][k1][l - 1] % 1E8

                dp[i][j][k][l] = int(answer % 1E8)

print(dp[n1][n2][k1][k2])
