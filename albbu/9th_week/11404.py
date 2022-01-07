from math import inf

def printTable(table) : # 보기 편한 출력
    maxStr = 3
    print("")
    for i in range(len(table)) :
        for j in range(len(table[0])) :
            element = table[i][j]
            spaceNum = maxStr - len(str(element))
            if element == inf :
                element = "i"
        
            print(element,end=' ')
            print(" "*spaceNum,end='')
        
        print("\b")

def printAnswer(table) : # 답안용 출력
    for i in range(len(table)) :
        for j in range(len(table[0])) :
            print(table[i][j],end=" ")
        print("")


if __name__ == "__main__" :
    cityNum = int(input())
    busNum = int(input())

    costsTable = [[inf for i in range(cityNum)] for j in range(cityNum)] # 표를 전부 무한으로 초기화

    for tableIndex in range(cityNum) :
        costsTable[tableIndex][tableIndex] = 0 # 제자리는 0으로 초기화
    
    for busIndex in range(busNum) :
        abcInput = list(map(int,input().split()))

        srcCity = abcInput[0]
        dstCity = abcInput[1]
        cost = abcInput[2]

        if costsTable[srcCity-1][dstCity-1] > cost : # 같은 경로로 더 적은 비용이 있을 수 있음
            costsTable[srcCity-1][dstCity-1] = cost
        

    for routeIndex in range(cityNum) :
        for dstIndex in range(cityNum) :
            for srcIndex in range(cityNum) :

                if routeIndex == srcIndex or routeIndex == dstIndex or srcIndex == dstIndex : # route = 경유지, 경유지가 출발/도착점과 같거나 출발/도착점이 서로 같은경우 제외
                    continue
                
                directCost = costsTable[srcIndex][dstIndex] # 출발지에서 도착지로 바로 갔을 때의 비용
                chkPointCost = costsTable[srcIndex][routeIndex] + costsTable[routeIndex][dstIndex] # 경유지를 거쳐갈 때의 비용
                
                if directCost > chkPointCost :
                    costsTable[srcIndex][dstIndex] = chkPointCost # 경유지 비용이 적으면 교체
    
    for srcIndex in range(cityNum) :
        for dstIndex in range(cityNum) :
            if costsTable[srcIndex][dstIndex] == inf : # 못 가는 경우는 0으로 만들어줌
                costsTable[srcIndex][dstIndex] = 0
    
    printAnswer(costsTable)
