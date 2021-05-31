
def getCompLocation(alphaLine,bravoLine) : # 상대거리 구하는 함수, 두 선분이 일직선상에 있을 때 호출
    checkAxis = 0

    if alphaLine[0][0] == alphaLine[1][0] : # x좌표가 모두 같을 경우, y좌표를 비교
        checkAxis = 1
    
    alphaStartLoc = alphaLine[0][checkAxis]
    alphaEndLoc = alphaLine[1][checkAxis]

    bravoStartLoc = bravoLine[0][checkAxis]
    bravoEndLoc = bravoLine[1][checkAxis]

    if alphaStartLoc > alphaEndLoc : # 첫번째 선분의 시작점의 좌표가 끝점보다 클 경우, 교환
        alphaStartLoc = alphaLine[1][checkAxis]
        alphaEndLoc = alphaLine[0][checkAxis]
    
    if bravoStartLoc > bravoEndLoc : # 두번째 선분 교환
        bravoStartLoc = bravoLine[1][checkAxis]
        bravoEndLoc = bravoLine[0][checkAxis]

    if alphaStartLoc <= bravoEndLoc and alphaEndLoc >= bravoStartLoc : # 선분이 일직선상에서 겹칠 경우
        
        return True 
    
    else : # 겹치지 않을 경우
        return False


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
    
    if bravoCheck <= 0 and alphaCheck <= 0 :
        crossChecker = True
    
        if bravoStart == 0 and alphaStart == 0 and bravoEnd == 0 and alphaEnd == 0 : # 두 선분이 일직선 상에 있을 때
            crossChecker = getCompLocation(alphaLine,bravoLine)
            
    return crossChecker

def combLines() : # C(n,2)경우의 수를 다 조합해서 교차 하는지 판별
    global lineList

    lineNum = len(lineList)
    
    for combIndex in range(lineNum) : # lineList[combIndex] = 기준 선분
        originGroup = lineList[combIndex].getGroup() # 선분의 원래 그룹번호 저장

        for lineIndex in range(combIndex+1,lineNum) : # lineList[lineIndex] = 비교 선분

            if checkCrossing(lineList[combIndex].point,lineList[lineIndex].point) : # 교차여부 판별
                
                if lineList[lineIndex].getGroup() != lineIndex : # 비교 선분의 그룹번호가 이미 변경된 경우
                    lineList[combIndex].setGroup(lineList[lineIndex].getGroup()) # 기준 선분의 그룹번호 변경
                    
                    for changeIndex in range(lineNum) : 
                        if lineList[changeIndex].getGroup() == originGroup : # 이미 기준 선분의 그룹번호로 변경된 선분들 찾기
                            lineList[changeIndex].setGroup(lineList[lineIndex].getGroup()) # 비교 선분의 그룹번호로 변경
            
                else : # 비교 선분의 그룹번호가 그대로일 경우
                    lineList[lineIndex].setGroup(lineList[combIndex].getGroup()) # 비교 선분의 그룹번호 변경

    return

class line : # 선분 클래스
    def __init__(self,pointInfo,groupNum) :
        self.point = pointInfo # 좌표, tuple형
        self.group = groupNum # 그룹번호, 리스트내의 순서를 따름
    
    def setGroup(self,groupNum) : # 그룹번호 변경
        self.group = groupNum
    
    def getGroup(self) : # 그룹번호 반환
        return self.group


if __name__ == "__main__" :

    lineNum = int(input())

    lineList = []
    lineGroup = []

    for lineIndex in range(lineNum) :
        lineInput = list(map(int,input().split()))
        
        startPoint = (lineInput[0],lineInput[1]) # 시작점 좌표
        endPoint = (lineInput[2],lineInput[3]) # 끝점 좌표
        
        singleLine = line((startPoint,endPoint),lineIndex) # 선분 객체 생성

        lineList.append(singleLine) # 객체를 리스트에 저장

    combLines() # 선분 조합, 교차 여부 판별, 그룹번호 지정

    groupList = [lineList[groupIndex].getGroup() for groupIndex in range(lineNum)] # 모든 선분의 그룹번호를 순서대로 리스트에 저장
    countList = []
    
    for lineIndex in range(lineNum) :
        countList.append(groupList.count(lineIndex)) # 각 그룹번호의 갯수 세기
    
    count = 0

    for countIndex in range(lineNum) :
    
        if countList[countIndex] > 0 : # 그룹번호의 갯수가 1이상인 경우만 세기
            count += 1
    
    print(count) # 그룹의 갯수 출력
    print(max(countList)) # 그룹의 최댓값 출력
