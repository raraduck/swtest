# N, C = 9, 3
# unordered_num = [1, 3, 3, 3, 2, 2, 2, 1, 1]

N, C = [int(el) for el in input().split()]
unordered_num = [int(el) for el in input().split()]

dict_num = {}

for el in unordered_num:
    dict_num.setdefault(el,0)
    dict_num[el]+=1

print(dict_num)


# for k,v in dict_num.items():
# dict_cnt_k = {}
# for el in unordered_num:
#     cnt_k = dict_num[el]
#     dict_cnt_k.setdefault(cnt_k, []).append(el)

# print(dict_cnt_k)

sorted_dict = dict(sorted(dict_num.items(), key=lambda x: x[1], reverse=True))
# sorted_dict = dict(sorted(dict_num.items(), reverse=True))

print(sorted_dict)

ret = []
for k, v in sorted_dict.items():
    tmp = [k] * v
    # print(tmp)
    ret += tmp
#     # ret = ret + k * v

print(*ret)