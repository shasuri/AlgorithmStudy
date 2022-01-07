import math

def ccwCheck(alphaPoint,bravoPoint,charliePoint) 

    checker = (bravoPoint[0]-alphaPoint[0])*(charliePoint[1]-alphaPoint[1]) - (bravoPoint[1]-alphaPoint[1])*(charliePoint[0]-alphaPoint[0])
    
    if checker != 0 :
        checker /= abs(checker)
        checker = int(checker)
    return checker


def getDistance(alphaPoint,bravoPoint) :
    return math.sqrt( (alphaPoint[0]-bravoPoint[0])**2 + (alphaPoint[1]-bravoPoint[1])**2 )


if __name__ == "__main__" :
    pointNum = int(input())
    pointList = []
    cornerIndex = None

    for pointIndex in range(pointNum) :
        pointInput = list(map(int,input().split()))

        if cornerIndex == None :
            cornerIndex = pointIndex
        
        else :
            if pointInput[1] < pointList[cornerIndex][1] :
                cornerIndex = pointIndex
            
            elif pointInput[1] == pointList[cornerIndex][1] :
                if pointInput[0] < pointList[cornerIndex][0] :
                    cornerIndex = pointIndex

        pointList.append(pointInput)

    sortList = sorted(pointList,key=lambda dot:(dot[0],dot[1]))
    
    grahamStack = [sortList[0],sortList[1]]

    stackIndex = 0

    while stackIndex < len(sortList) :
        if len(grahamStack) <= 1 :
            grahamStack.append(sortList[stackIndex])
    
            stackIndex += 1
            continue
        if stackIndex >= len(sortList) :
            break
        topStack = grahamStack[-1]
        secondStack = grahamStack[-2]
        stackTarget = sortList[stackIndex]
        
        if ccwCheck(secondStack,topStack,stackTarget) > 0 :
            
            grahamStack.append(stackTarget)

            stackIndex += 1
        else :
            grahamStack.pop()

        if stackIndex >= len(sortList) :
            break

    answer = len(grahamStack)

    sortList = sorted(pointList,key=lambda dot:(dot[0],dot[1]),reverse=True)

    grahamStack = [sortList[0],sortList[1]]
        
    stackIndex = 0

    while stackIndex < len(sortList) :
        if len(grahamStack) <= 1 :
            grahamStack.append(sortList[stackIndex])
    
            stackIndex += 1
            continue
        if stackIndex >= len(sortList) :
            break

        topStack = grahamStack[-1]
        secondStack = grahamStack[-2]
        stackTarget = sortList[stackIndex]

        if ccwCheck(secondStack,topStack,stackTarget) > 0 :            
            grahamStack.append(stackTarget)
            stackIndex += 1
        else :
            grahamStack.pop()
        if stackIndex >= len(sortList) :
            break
    
    answer += len(grahamStack) - 2

    print(answer)
    
