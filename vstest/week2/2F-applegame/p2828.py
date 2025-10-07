# N = 5
# M = 1
# J = 3

# P = [1, 5, 3]

N, M = [int(el) for el in input().split()]
J = int(input())
P = []
for idx in range(J):
    P.append(int(input()))
# 0|1|2|3|4|5|
#   M        
#   M_M     

width_M = M
pos_M = 1
area_M = lambda p, m: list(range(p, p + m))
valid_Pos = N - M + 1

# print(area_M(1,M), valid_Pos)
# print(area_M(2,M), valid_Pos)
# print(area_M(3,M), valid_Pos)

ret = 0
if valid_Pos == 1:
    print(ret)
    pass
else:
    for p in P:
        current_M = area_M(pos_M,M)
        if p in current_M:
            # print(f"p:{p}, pos_M: {pos_M}, ret: {ret}")
            pass
        else:
            if p > current_M[-1]:
                dist = p - current_M[-1]
                pos_M = pos_M + dist
                ret += dist
            elif p < current_M[0]:
                dist = p - current_M[0]
                pos_M = pos_M + dist
                ret += (-1*dist)
            # print(f"p:{p}, pos_M: {pos_M}, ret: {ret}")
            # print(ret)
print(ret)
