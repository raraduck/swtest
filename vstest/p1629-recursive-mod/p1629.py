A, B, C = [int(el) for el in input().split()]

def go(a, b, c):
    if (b == 1):
        return a
    else:
        el = go(a, b//2, c)
        el1 = el % c
        el2 = el % c
        el = (el1 * el2) % c
        return el

Ans = go(A, B, C)
print(Ans)