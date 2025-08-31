# while True:
#     A = input()
#     if not A:      # 엔터만 치면 종료
#         break
#     ones = ''.join(['1' for el in range(len(A))])
#     A = int(A)
#     # for i in range(A):
#     #     ones += '1'
#     # print(f"{A}: {ones}")
#     _ones = ones
#     while True:
#         _ones = int(str(_ones) + '1')
#         if _ones % A == 0:
#             print(len(f"{_ones}"))
#             break

import sys

for line in sys.stdin:          # EOF까지 안전하게 읽기
    s = line.strip()
    if not s:                   # 공백 줄이면 건너뜀 (선택)
        continue
    n = int(s)

    # 최소 길이 k s.t. 111...1(k개)가 n으로 나누어 떨어짐
    rem = 0
    k = 0
    while True:
        k += 1
        rem = (rem * 10 + 1) % n
        if rem == 0:
            print(k)
            break