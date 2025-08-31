# 첫째 줄에 단어의 수 N이 주어진다. (1 ≤ N ≤ 100)
# 다음 N개 줄에는 A와 B로만 이루어진 단어가 한 줄에 하나씩 주어진다. 
# 단어의 길이는 2와 100,000사이이며, 
# 모든 단어 길이의 합은 1,000,000을 넘지 않는다.

N = int(input())
W = []
for i in range(N):
    tmp = input().upper()
    W.append(tmp)

print(W)

for w in W:
    stack = []
    for i, c in enumerate(w):
        if len(stack) == 0:
            stack.append(c)
        else:
            if c == stack[-1]:
                stack.pop()
            else:
                stack.append(c)
    if len(stack) == 0:
        print(w)