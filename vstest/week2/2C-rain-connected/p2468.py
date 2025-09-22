import sys
sys.setrecursionlimit(10**6)

DEBUG = 0

dy=[-1, 0, 1, 0]
dx=[0, 1, 0, -1]

def display(N, arr):
    for r in range(N):
        print(arr[r])

N = int(input())
maxVal = 0
Mat = []
for r in range(N):
    row = [int(el) for el in input().split()]
    Mat.append(row[:N])
    maxNew = max(row)
    maxVal = maxNew if maxNew > maxVal else maxVal

def dfs(_y, _x, arr, _N):
    arr[_y][_x] = 2
    for i in range(4):
        ny = _y + dy[i]
        nx = _x + dx[i]
        if N > ny and ny >= 0 and N > nx and nx >= 0:
            if arr[ny][nx] == 1:
                dfs(ny, nx, arr, _N)

n_of_components = []
for level in range(0, maxVal + 1):
    Arr = [[0 if el <= level else 1 for el in row] for row in Mat ]

    if DEBUG: print()
    if DEBUG: print()
    if DEBUG: print(level)
    if DEBUG: display(N, Arr)
    
    cnt = 0
    for y in range(N):
        for x in range(N):
            if Arr[y][x] == 1:
                dfs(y, x, Arr, N)
                cnt+=1
    n_of_components.append(cnt)

    if DEBUG: print()
    if DEBUG: display(N, Arr)

if DEBUG: print()
if DEBUG: print(n_of_components)

print(max(n_of_components))