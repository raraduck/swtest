# 4 6
# 101111
# 101010
# 101011
# 111011

# 4 6
# 110110
# 110110
# 111111
# 111101

# 2 25
# 1011101110111011101110111
# 1110111011101110111011101

# 7 7
# 1011111
# 1110001
# 1000001
# 1000001
# 1000001
# 1000001
# 1111111

from collections import deque


# # 초기화
# dq = deque([1, 2, 3])

# # 오른쪽 끝에 원소 추가
# dq.append(4)        # [1, 2, 3, 4]

# # 왼쪽 끝에 원소 추가
# dq.appendleft(0)    # [0, 1, 2, 3, 4]

# # 오른쪽 끝에서 꺼내기
# x = dq.pop()        # x=4, dq=[0,1,2,3]

# # 왼쪽 끝에서 꺼내기
# y = dq.popleft()    # y=0, dq=[1,2,3]

# N, M = 4, 6

def display(A):
    for ely in A:
        print(ely)


N, M = [int(el) for el in input().split()]
Arr = []
for el in range(N):
    row = [int(el) for el in list(input())]
    Arr.append(row)

dy = [-1, 0, 1, 0]
dx = [ 0, 1, 0,-1]

dq = deque([(0,0,1)])

def bfs():
    y, x, v = dq.popleft()
    if y == (N-1) and x == (M-1):
        print(f"{v}")
        dq.clear()
        return
    # print(f"({y}, {x}, {v})")
    Arr[y][x] = 2
    # display(Arr)

    # north check
    ny = y + dy[0]
    nx = x + dx[0]
    if ny >= 0 and ny < N and nx >= 0 and nx < M:
        if Arr[ny][nx] == 1:
            # bfs(ny, nx)
            dq.append((ny, nx, v+1))
            Arr[ny][nx] = 2
    # east check
    ny = y + dy[1]
    nx = x + dx[1]
    if ny >= 0 and ny < N and nx >= 0 and nx < M:
        if Arr[ny][nx] == 1:
            dq.append((ny, nx, v+1))
            Arr[ny][nx] = 2
    # south check
    ny = y + dy[2]
    nx = x + dx[2]
    if ny >= 0 and ny < N and nx >= 0 and nx < M:
        if Arr[ny][nx] == 1:
            dq.append((ny, nx, v+1))
            Arr[ny][nx] = 2
    # west check
    ny = y + dy[3]
    nx = x + dx[3]
    if ny >= 0 and ny < N and nx >= 0 and nx < M:
        if Arr[ny][nx] == 1:
            dq.append((ny, nx, v+1))
            Arr[ny][nx] = 2
    # return len(dq)


while len(dq) != 0:
    bfs()

