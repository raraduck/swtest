N = int(input())
M = int(input())
S = [int(el) for el in input().split()]

print(N)
print(M)
print(S)

def combi(n, r, start):
    if len(L) == 2:
        print(f"{L} {sum(L)}")
    else:
        for i in range(start, n):
            L.append(S[i])
            combi(n, r, i+1)
            L.pop()
L = []
combi(N, 2, 0)
