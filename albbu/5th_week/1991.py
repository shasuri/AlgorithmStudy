def printList(listInput): # 순회 경로 출력용 함수
    for listIndex in listInput :
        print(listIndex,end="")
    print('')

class singleNode : # 노드 클래스 정의
    
    def __init__(self,inputVal) :
        self.value = inputVal
        
        self.leftChild = None
        self.rightChild = None
        self.parent = None

    def adoptLeft(self,inputNode) :
        self.leftChild = inputNode
    
    def adoptRight(self,inputNode) :
        self.rightChild = inputNode

    def admitParent(self,inputNode) :
        self.parent = inputNode

    def forwardTour(self) : # 전위 순회
        forwardRoute = []

        forwardRoute.append(self.value) # 노드 정보 경로에 추가

        if self.leftChild != None : # 왼쪽 노드
            forwardRoute += self.leftChild.forwardTour()

        if self.rightChild != None : # 오른쪽 노드
            forwardRoute += self.rightChild.forwardTour()
        
        return forwardRoute

    def centerTour(self) : # 중위 순회
        centerRoute = []

        if self.leftChild != None :
            centerRoute += self.leftChild.centerTour()
        
        centerRoute.append(self.value)

        if self.rightChild != None :
            centerRoute += self.rightChild.centerTour()

        return centerRoute

    def backwardTour(self) : # 후위 순회
        backwardRoute = []

        if self.leftChild != None :
            backwardRoute += self.leftChild.backwardTour()
        
        if self.rightChild != None :
            backwardRoute += self.rightChild.backwardTour()

        backwardRoute.append(self.value)

        return backwardRoute


if __name__ == "__main__" :
    alpha = ord('A') # 알파벳 아스키코드 65 저장

    nodeList = []
    nodeNum = int(input())
    
    for nodeIndex in range(nodeNum) :
        nodeList.append(singleNode(chr(alpha+nodeIndex))) # 알파벳을 value로 노드 생성후 리스트 저장
    
    # nodeList[0].admitParent(singleNode(None))

    for nodeIndex in range(nodeNum) :
        pathInput = input().split()

        parentNumber = ord(pathInput[0]) - alpha # 부모노드의 리스트 위치

        if pathInput[1] != '.' :
            leftNumber = ord(pathInput[1]) - alpha # 왼쪽 자식의 리스트 위치
            nodeList[parentNumber].adoptLeft(nodeList[leftNumber])
            nodeList[leftNumber].admitParent(nodeList[parentNumber])
        # else :
        #     nodeList[parentNumber].adoptLeft(singleNode(None))
        
        if pathInput[2] != '.' :
            rightNumber = ord(pathInput[2]) - alpha # 오른쪽 자식의 리스트 위치
            nodeList[parentNumber].adoptRight(nodeList[rightNumber])
            nodeList[rightNumber].admitParent(nodeList[parentNumber])
        # else :
        #     nodeList[parentNumber].adoptRight(singleNode(None))
    '''
    for nodeIndex in range(nodeNum) : # 각 노드의 부모, 왼쪽 자식, 오른쪽 자식을 순서대로 출력
        print(f"{nodeList[nodeIndex].value} : {nodeList[nodeIndex].parent.value}, {nodeList[nodeIndex].leftChild.value}, {nodeList[nodeIndex].rightChild.value}")
    '''

    forwardRoute = nodeList[0].forwardTour()
    centerRoute = nodeList[0].centerTour()
    backwardRoute = nodeList[0].backwardTour()

    printList(forwardRoute)
    printList(centerRoute)
    printList(backwardRoute)
