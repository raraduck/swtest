# M, N, K = 5, 7, 3
# rects = [
#     [[0, 2], [4, 4]],
#     [[1, 1], [2, 5]],
#     [[4, 0], [6, 2]],
# ]

M, N, K = [int(el) for el in input().split()]
rects = []
for k in range(K):
    rects.append([int(el) for el in input().split()])

Mat=[[1]*N for idx in range(M)]

# print(len(Mat), len(Mat[0]))
# for i in range(M):
#     print(Mat[i])

for y in range(M):
    for x in range(N):
        for rect in rects:
            if rect[3] > y and y >= rect[1]:
                if rect[2] > x and x >= rect[0]:
                    Mat[y][x] = 0

# print(len(Mat), len(Mat[0]))
# for i in range(M):
#     print(Mat[i])

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

def dfs(y, x, mat, c):
    c += 1
    mat[y][x] = 2
    for _dy, _dx in zip(dy, dx):
        ny = y+_dy
        nx = x+_dx
        if (M > ny and ny >= 0 and N > nx and nx >= 0):
            if mat[ny][nx] == 1:
                c = dfs(ny, nx, mat, c)
    return c


ret = []
for y in range(M):
    for x in range(N):
        if Mat[y][x] == 1:
            cnt = 0
            cnt = dfs(y, x, Mat, cnt)
            ret.append(cnt)
            
ret.sort()
print(len(ret))
print(*ret)