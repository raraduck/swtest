print("p9375")

T = int(input("테스트케이스: "))


for i in range(1, 1+int(T)):
    print(f"테스트케이스 {i}")
    N = int(input("의상 수: "))
    Data = {}  # 테스트케이스마다 초기화
    for j in range(1, 1 + N):
        CN, CT = input("<의상이름> <종류>: ").split()
        Data.setdefault(CT, [""]).append(CN)
    for (t, n) in Data.items():
        print(f"의상이름과 종류: {n} {t}")
    
    Answer = 1
    for (t, n) in Data.items():
        Answer *= len(Data[t])
    print(f"Answer: {Answer -1}")