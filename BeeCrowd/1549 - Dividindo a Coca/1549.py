import math

c = int(input())

for i in range(c):
    n, L = map(int, input().split())
    b, B, Ht = map(int, input().split())

    L /= n

    if B != b:
        Vt = 1/3 * math.pi * Ht * ((B**2) + B * b + (b ** 2))
        Hc = (Ht * B) / (B - b)
        Vc = 1/3 * math.pi * (B**2) * Hc

        Vcm = Vc - Vt
        Hcm = Hc - Ht

        Ha = ((Vcm + L) * (Hcm**3) / Vcm)**(1/3)
        Hy = Hc - Ha
        Hx = Ht - Hy
    else:
        V = math.pi * (B**2) * Ht
        Hx = (L * Ht / V)

    print("{:.2f}".format(Hx))
