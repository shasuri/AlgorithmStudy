testCase = int(input())
answer = 0

for i in range(testCase) :
    params = list(map(int,input().split()))

    l = params[0]
    a = params[1]
    b = params[2]

    biStr = input()

    c = biStr[0]
    g = 1

    if b >= 0 :
        answer = (a + b) * l

    if b < 0 :
        for j in biStr[1:] :
            if c != j :
                g += 1
                c = j

        answer = a * l + b * (g//2 + 1)
        
    print(answer)