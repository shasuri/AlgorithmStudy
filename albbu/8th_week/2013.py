import math

def getDistance(alphaPoint,bravoPoint) :
    return (bravoPoint[0] - alphaPoint[0]) ** 2 + (bravoPoint[1] - alphaPoint[1]) ** 2

def getCompLocation(alphaLine,bravoLine) : # 상대거리 구하는 함수, 두 선분이 일직선상에 있을 때 호출
    checkAxis = 0

    if alphaLine[0][0] == alphaLine[1][0] : # x좌표가 모두 같을 경우, y좌표를 비교
        checkAxis = 1
    
    alphaStartLoc = alphaLine[0]
    alphaEndLoc = alphaLine[1]
    
    bravoStartLoc = bravoLine[0]
    bravoEndLoc = bravoLine[1]
    
    if alphaStartLoc[checkAxis] > alphaEndLoc[checkAxis] : # 첫번째 선분의 시작점의 좌표가 끝점보다 클 경우, 교환
        alphaStartLoc = alphaLine[1]
        alphaEndLoc = alphaLine[0]
    
    if bravoStartLoc[checkAxis] > bravoEndLoc[checkAxis] : # 두번째 선분 교환
        bravoStartLoc = bravoLine[1]
        bravoEndLoc = bravoLine[0]

    if alphaStartLoc[checkAxis] <= bravoEndLoc[checkAxis] and alphaEndLoc[checkAxis] >= bravoStartLoc[checkAxis] : # 선분이 일직선상에서 겹칠 경우
        return True
        # if getDistance(alphaStartLoc,bravoEndLoc) >= getDistance(alphaEndLoc,bravoStartLoc) :
        #     return True,alphaStartLoc,bravoEndLoc
        
        # else :
        #     return True,bravoStartLoc,alphaEndLoc
    
    else : # 겹치지 않을 경우
        return False

def getStartEnd(pointList) :
    checkAxis = 0
    
    if pointList[0][0] == pointList[1][0] :
        checkAxis = 1
    
    minLoc = (1001,1001)
    maxLoc = (-1,-1)

    for pointIndex in range(len(pointList)) :
        
        if pointList[pointIndex][checkAxis] >= maxLoc[checkAxis] :

            maxLoc = pointList[pointIndex]
        
        if pointList[pointIndex][checkAxis] <= minLoc[checkAxis] :
            
            minLoc = pointList[pointIndex]

    return (minLoc,maxLoc)


def ccwCheck(alphaPoint,bravoPoint,charliePoint) : # 시계방향, 반시계 방향 판별

    checker = (bravoPoint[0]-alphaPoint[0])*(charliePoint[1]-alphaPoint[1]) - (bravoPoint[1]-alphaPoint[1])*(charliePoint[0]-alphaPoint[0])
    
    if checker != 0 :
        checker /= abs(checker)
        checker = int(checker)
    #time
    return checker

def checkCrossing(alphaLine,bravoLine) : # 교차 여부 판별 함수
    crossChecker = False
    
    bravoStart = ccwCheck(alphaLine[0],alphaLine[1],bravoLine[0])
    bravoEnd = ccwCheck(alphaLine[0],alphaLine[1],bravoLine[1])

    alphaStart = ccwCheck(bravoLine[0],bravoLine[1],alphaLine[0])
    alphaEnd = ccwCheck(bravoLine[0],bravoLine[1],alphaLine[1])

    bravoCheck = bravoStart * bravoEnd
    alphaCheck = alphaStart * alphaEnd
    
    # if bravoCheck <= 0 and alphaCheck <= 0 :
    #     crossChecker = True
    
    if bravoStart == 0 and alphaStart == 0 and bravoEnd == 0 and alphaEnd == 0 : # 두 선분이 일직선 상에 있을 때
        crossChecker = getCompLocation(alphaLine,bravoLine)
            
    return crossChecker

if __name__ == "__main__" :
    lineNum = int(input())

    lineList = []

    for lineIndex in range(lineNum) :
        pointInput = list(map(float,input().split()))

        alphaX = pointInput[0]
        alphaY = pointInput[1]
        #alphaLine = 

        bravoX = pointInput[2]
        bravoY = pointInput[3]
        #bravoLine = 
        line = ((alphaX,alphaY),(bravoX,bravoY))

        lineList.append(line)

    crossList = [lineList[0]]
    overCounter = lineNum

    for lineIndex in range(1,lineNum) :
        
        popList = []
        for crossIndex in range(len(crossList)) :
            
            checkResult = checkCrossing(lineList[lineIndex],crossList[crossIndex])

            if checkResult :    
                popList.append(crossIndex)
                overCounter -= 1
        
        checkList = [lineList[lineIndex][0],lineList[lineIndex][1]]
        
        popList.reverse()
        
        for popIndex in range(len(popList)) :
            checkList.append(crossList[popList[popIndex]][0])
            checkList.append(crossList[popList[popIndex]][1])
            crossList.pop(popList[popIndex])

        finalLine = getStartEnd(checkList)

        crossList.append(finalLine)
    #print(crossList)
            
    #print(group)
    print(len(crossList))
            