def findShortcut(india) :
    global delta

    if india in delta : # 주어진 숫자가 미리 계산 되있는지를 확인
        return delta[india] # 미리 계산되 있으면 반환

    paths = [-1,-1,-1] 

    if india % 3 == 0 : # 연산 1
        paths[0] = findShortcut(india / 3)
    
    if india % 2 == 0 : # 연산 2
        paths[1] = findShortcut(india / 2)

    paths[2] = findShortcut(india - 1) # 연산 3

    pathIndex = 0
    pathCount = 0
    
    while pathCount < 3 : 
        if paths[pathIndex] < 0 :
            paths.pop(pathIndex) # 연산이 안된 부분은 제외
        else :
            pathIndex += 1
        pathCount += 1
    
    myShortcut = min(paths) + 1 # 최소거리 판별, 이 연산을 거쳤으니 +1
    delta[india] = myShortcut # 최단거리 등록
    
    return myShortcut
 

if __name__ == "__main__" :
    november = int(input()) # 숫자 입력
    
    delta = {} # 최단 횟수들을 기억할 딕셔너리 자료형
    delta[1] = 0
    delta[2] = 1
    delta[3] = 1
    
    for deltaIndex in range(1,1000000) : # 문제에 주어진 최대 입력 만큼 미리 계산
        findShortcut(deltaIndex)

    calcCount = findShortcut(november) # 주어진 숫자 계산, 이제 생각해보니까 함수 안넣고 그냥 딕셔너리로 찾아도 되겠네?
    print(calcCount)
    