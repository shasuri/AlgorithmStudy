import sys

class singleNode : # 노드 클래스 정의
    
    def __init__(self,inputVal) :
        self.value = inputVal
        
        self.parent = None
        self.children = []

        self.parentPath = 0
        
    def adoptChild(self,inputNode) :
        (self.children).append(inputNode)

    def admitParent(self,inputNode,pathLength) :
        self.parent = inputNode
        self.parentPath = pathLength
    
    def tour(self) : # 순회
        global maxRadian # 최댓값 전역변수
        childrenPath = [] # 자식들 간의 거리를 저장할 리스트

        chosenPath = self.parentPath # 자식들 중 제일 긴 거리와 부모 간의 거리를 합쳐줄 변수
        
        for childIndex in range(len(self.children)) :
            childrenPath.append(self.children[childIndex].tour()) # 재귀
        
        if len(childrenPath) < 1 : # 자식이 없을 경우
            pass
        
        if len(childrenPath) == 1 : # 자식이 하나일 경우
            chosenPath += childrenPath[0]

            if maxRadian < childrenPath[0] : # 최댓값 비교
                maxRadian = childrenPath[0]
        
        if len(childrenPath) > 1 : # 자식이 여럿일 경우
            firstLong = max(childrenPath) # 첫번째로 먼 자식
            childrenPath.remove(firstLong)
            secondLong = max(childrenPath) # 두번째로 먼 자식
            
            chosenPath += firstLong # 부모 간의 거리와 제일 먼 자식을 합한 뒤, 반환

            if maxRadian < firstLong + secondLong : # 최댓값 비교
                maxRadian = firstLong + secondLong
        
        return chosenPath


if __name__ == "__main__" :
    sys.setrecursionlimit(10000) # 재귀 제한 늘리기

    nodeNum = int(input())
    nodeList = []
    maxRadian = 0 # 최댓값 전역변수

    for nodeIndex in range(nodeNum) :
        nodeList.append(singleNode(nodeIndex+1))

    for nodeIndex in range(nodeNum-1) :
        pathInfo = input().split()

        parentIndex = int(pathInfo[0])
        childIndex = int(pathInfo[1])
        pathLength = int(pathInfo[2])

        parentNode = nodeList[parentIndex-1]
        childNode = nodeList[childIndex-1]
        
        parentNode.adoptChild(childNode)
        childNode.admitParent(parentNode,pathLength) # 간선 가중치를 저장
    
    nodeList[0].tour() # 순회 시작
    print(maxRadian)
