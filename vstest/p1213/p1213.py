import sys

print("p1213")

STR = input().upper()
if len(STR) > 50:
    print("I'm Sorry Hansoo")
    sys.exit(0)

# 문자열을 일단 쪼갬
print(f"{STR}")
# C_STR = STR.split("")
# C_STR = list(STR)
C_STR = [c for c in STR]
print(f"{C_STR}")

# 문자열로 순열을 생성
# 다만 for문으로 하기에는 50최대 단어가 있으므로
# 재귀함수를 사용해서 완전탐색 해야함

# 근데 사전수능로 앞서는것을 하나만 출력하면 되는것같네
# 그러다면 가장 최초로 팰린드롬이 발견되는 경우만 출력하고 종료

# 일단 단어를 알파벳 순으로 정렬해야함

C_STR.sort()
print(f"{C_STR}")

def is_pallindrom(l_str):
    str1 = l_str
    str2 = list(reversed(l_str))
    return str1 == str2

TMP = C_STR
def recursive(n, r, depth):
    # print(f"{n}:{r}:{depth}")
    if (depth == r):
        # tmp = ''.join(TMP)
        # print(f"{tmp}")
        if is_pallindrom(TMP):
            tmp = ''.join(TMP)
            print(f"{tmp}")
            sys.exit(0)
    else:
        for i in range(depth,n):
            # TMP.append(C_STR[i])
            TMP[i], TMP[depth] = TMP[depth], TMP[i]
            recursive(n, r, depth+1)
            # TMP.pop()
            TMP[i], TMP[depth] = TMP[depth], TMP[i]

recursive(len(C_STR), len(C_STR), 0)
print(f"I'm Sorry Hansoo")