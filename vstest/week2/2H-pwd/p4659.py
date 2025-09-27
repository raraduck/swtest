
while True:
    checker={1:0,2:0,3:0}
    pwd = input()
    if pwd == "end":
        break

    for el in pwd:
        if el in ['a','e','i','o','u']:
            checker[1] = 1
            break
    print(f"check1: {checker[1]}")

    case=0
    prev_case=0
    cnt={1:3, 2:3}
    for el in pwd:
        if el in ['a','e','i','o','u']:
            case=1
        else:
            case=2
        if prev_case != case:
            cnt={1:3, 2:3}
        cnt[case]-=1
        if cnt[case]==0:
            checker[2] = 0
            break
        else:
            checker[2] = 1
        prev_case=case
    print(f"check2: {checker[2]}")
        
    checker[3]=1
    el_1=''
    el_2=''
    for idx, el in enumerate(pwd):
        if idx >= 1:
            if el_1 == el:
                if el in ['e', 'o']:
                    if el_2 == el:
                        checker[3] = 0
                        break
                else:
                    checker[3] = 0
                    break
            else:
                checker[3] = 1
        el_2 = el_1
        el_1 = el
    print(f"check3: {checker[3]}")

    if sum(list(checker.values())) == 3:
        print(f"<{pwd}> is acceptable.")
    else:
        print(f"<{pwd}> is not acceptable.")