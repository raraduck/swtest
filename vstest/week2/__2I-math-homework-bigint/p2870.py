N = int(input()) # 4 # 2 # int(input())
W_list = [
    # "lo3za4",
    # "01"

    # "43silos0",
    # "zita002",
    # "le2sim",
    # "231233",

    # "01bond",
    # "02james007",
    # "03bond",
    # "04austinpowers000",
]

for i in range(N):
    W_list.append(input())

# print(N, W_list)

Num_list = []

import re
for w in W_list:
    result = re.split(r"[a-z]+", w)
    result = [el.lstrip("0") or "0" for el in result if el]
    Num_list+=result

# from natsort import natsorted

Num_list = sorted([int(el) for el in Num_list])
# print(Num_list)
for el in Num_list:
    print(el)