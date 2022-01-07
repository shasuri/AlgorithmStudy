testCases = int(input())

for i in range(0,testCases) :
    cycleLen = int(input())
    cycle = input().split()

    for c in range(0,cycleLen) :
        cycle[c] = int(cycle[c])

    sCycle = []
    rChk = []

    for y in range(0,cycleLen) :
        sCycle.append(cycle[y] + y)
        rChk.append(sCycle[y]%cycleLen)

    if len(set(rChk)) == len(rChk):
        print("YES")
    else : 
        print("NO")

    
