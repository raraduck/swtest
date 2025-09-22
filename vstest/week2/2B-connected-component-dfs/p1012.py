DEBUG = 0
# T = 1
# M, N, K = 10, 8, 17
# Pos=[ 
#     [0, 0], [1, 0], [1, 1], [4, 2], [4, 3], 
#     [4, 5], [2, 4], [3, 4], [7, 4], [8, 4], 
#     [9, 4], [7, 5], [8, 5], [9, 5], [7, 6], 
#     [8, 6], [9, 6],
# ]
# 1111
# 1010
# 1100
# 1000

# [0,0],[0,1],[0,2],[0,3]
# [1,0],[1,1],[1,2],[1,3]
# [2,0],[2,1],[2,2],[2,3]
# [3,0],[3,1],[3,2],[3,3]

def display(mat, n, m):
    print(">")
    for y in range(0,n):
        print(f"{mat[y]}")
        # for x in range(0,m):
        #     print(f"{map[y][x]} ")
    print("<")

def dfs(y,x, mat):
    mat[y][x] = 2
    if DEBUG: display(mat, N, M)
    display(MAT, N, M)
    for i in [0, 1, 2, 3]:
        ny = y + dy[i]
        nx = x + dx[i]
        is_land = 0
        if N > ny and ny >= 0 and M > nx and nx >= 0:
            is_land = mat[ny][nx]
        if is_land == 1:
            dfs(ny,nx, mat)

T = int(input())
for t in range(T):
    M, N, K = [int(el) for el in input().split()]
    Pos = [[int(el) for el in input().split()] for _ in range(K)]

    MAT = [[0] * M for _ in range(N)]

    for el in Pos:
        MAT[el[1]][el[0]] = 1

    if DEBUG: display(MAT, N, M)

    dy = [-1, 0, 1, 0]
    dx = [ 0, 1, 0,-1]

    cnt = 0
    for y in range(N):
        for x in range(M):
            if MAT[y][x] == 1:
                dfs(y,x, MAT)
                cnt+=1

    print(cnt, y, x)
display(MAT, N, M)