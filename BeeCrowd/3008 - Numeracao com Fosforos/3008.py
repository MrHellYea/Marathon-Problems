R = [0, 0, 1, 1, 2, 5, 7, 12]
T = R.copy()

for i in range(8, 10_001):
    R.append(R[i-2] + R[i-3] + R[i-4] + (3*R[i-5]) + (3*R[i-6]) + R[i-7])
    T.append((R[i] - R[i-6]) % 1_000_007)

n = int(input())
for _ in range(n):
    q = int(input())
    print(T[q])


