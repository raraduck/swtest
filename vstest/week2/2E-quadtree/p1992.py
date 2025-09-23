N = 8 # 1 <= N <= 64
IMG = [
    [1,1,1,1,0,0,0,0],
    [1,1,1,1,0,0,0,0],
    [0,0,0,1,1,1,0,0],
    [0,0,0,1,1,1,0,0],
    [1,1,1,1,0,0,0,0],
    [1,1,1,1,0,0,0,0],
    [1,1,1,1,0,0,1,1],
    [1,1,1,1,0,0,1,1],
]

# x:0~3, y:0~3
# x:4~8, y:0~3
# x:0~3, y:4~8

# n = len(N)
# x:0~N/2, y: 0~N/2
# x:N/2~N, y: 0~N/2
# x:0~N/2, y: N/2~N
# x:N/2~N, y: N/2~N

# direction = [
#     (0, n/2)
# ]
N = int(input())
IMG = [[int(el) for el in list(input().strip())] for _ in range(N)]

direction = (lambda y,x,w:[
    [(x,    x+w/2), (y,     y+w/2)],
    [(x+w/2,  w/2), (y,     y+w/2)],
    [(x,    x+w/2), (y+w/2,     w)],
    [(x+w/2,  w/2), (y+w/2,     w)],
])

def is_solid(y,x,w,img):
    counter = {0:0, 1:0}
    for i,r in enumerate(img):
        if (y+w > i) and (i >= y):
            for j,c in enumerate(r):
                if (x+w > j) and (j >= x):
                    counter[c] += 1
    if counter[0] == 0:
        return True, 1
    elif counter[1] == 0:
        return True, 0
    else:
        return False, None
    # return True if counter[0] == 0 or counter[1] == 0 else False

def dfs(y, x, w, img, acc):

    # print(f'({y},{x},{w})>>>')
    # for i,r in enumerate(img):
    #     if (y+w > i) and (i >= y):
    #         for j,c in enumerate(r):
    #             if (x+w > j) and (j >= x):
    #                 print(f"{c}", end=" ")
    #         print()
    # print(f'<<<')

    is_end, code = is_solid(y, x, w, img)
    if is_end:
        acc.append(str(code))
    else:
        acc.append("(")
        for d in direction(y,x,w):
            dfs(d[1][0], d[0][0], w/2, img, acc)
        acc.append(")")

acc = []
dfs(0, 0, N, IMG, acc)
ret = "".join(acc)
print(ret)