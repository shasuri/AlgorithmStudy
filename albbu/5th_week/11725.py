import sys

class singleNode : # 노드 클래스 정의
    
    def __init__(self,inputVal) :
        self.value = inputVal
        self.connectedNodes = [] # 해당노드와 연결된 모든 노드를 저장하는 리스트
        
        self.leftChild = None
        self.rightChild = None
        self.parent = None

    def connectNode(self,inputNode) : # 연결된 노드를 리스트에 저장
        (self.connectedNodes).append(inputNode)

    def adoptLeft(self,inputNode) :
        self.leftChild = inputNode
    
    def adoptRight(self,inputNode) :
        self.rightChild = inputNode

    def admitParent(self,inputNode) :
        self.parent = inputNode


def makeFamily(nodeList,searchNode) :
    global appleNode

    thisNode = nodeList[searchNode-1] # 가족을 구성할 노드
    connection = thisNode.connectedNodes # thisNode와 연결된 모든 노드
    #print(searchNode)

    for cntIndex in range(len(connection)) :
        cntNode = connection[cntIndex]

        if cntNode != thisNode.parent : # 연결된 노드가 부모가 아니면,

            if thisNode.leftChild == None : # 왼쪽 자식이 빈자리라면, 
                thisNode.adoptLeft(cntNode) # 왼쪽 자식으로 추가
                
                #print(thisNode.leftChild.value)

                cntNode.admitParent(thisNode) # 왼쪽 자식은 thisNode를 부모로 수용
            
            else : # 오른쪽
                thisNode.adoptRight(cntNode)
                cntNode.admitParent(thisNode)
            
            makeFamily(nodeList,cntNode.value) # 자식의 가족을 구성하기 위해 재귀
    
    if thisNode.leftChild == None : # 자식이 둘다 없을 경우
        thisNode.leftChild = appleNode # 왼쪽 자식을 빈 노드로 채움
    
    if thisNode.rightChild == None : # 자식이 하나만(왼쪽만) 있을 경우
        thisNode.rightChild = appleNode # 오른쪽 자식을 빈 노드로 채움

    return        


if __name__ == "__main__" :
    sys.setrecursionlimit(100000) # 재귀 제한 늘리기

    nodeNum = int(input()) # N 입력
    nodeList = [] # 노드들을 저장할 리스트
    
    rootNode = singleNode(None) # 1번 노드의 부모가 될 빈 노드
    appleNode = singleNode(None) # 정점노드 / 자식이 하나인 노드의 자식이 될 빈 노드

    for nodeIndex in range(nodeNum) : 
        nodeList.append(singleNode(nodeIndex+1)) # 노드 숫자만큼의 노드를 생성후 리스트에 저장

    for lineIndex in range(nodeNum-1) : 
        connection = input().split() # 연결된 노드 2개 표기

        alphaValue = int(connection[0])
        bravoValue = int(connection[1])

        nodeList[alphaValue-1].connectNode(nodeList[bravoValue-1]) # 서로의 연결 리스트에 서로를 추가
        nodeList[bravoValue-1].connectNode(nodeList[alphaValue-1])
    
    '''
    for nodeIndex in range(nodeNum) : # 상호간의 노드가 잘 연결 되었는지 출력
        print(f"{nodeList[nodeIndex].value} : {[(nodeList[nodeIndex].connectedNodes)[cntIndex].value for cntIndex in range(len(nodeList[nodeIndex].connectedNodes))]}")
    '''

    nodeList[0].admitParent(rootNode) # 1번노드의 부모를 빈 노드로 설정
    searchNode = 1 # 가족을 구성할 노드 번호
    
    makeFamily(nodeList,searchNode) # 1번노드 부터 가족 구성

    '''  
    for nodeIndex in range(nodeNum) : # 각 노드의 부모, 왼쪽 자식, 오른쪽 자식을 순서대로 출력
        print(f"{nodeList[nodeIndex].value} : {nodeList[nodeIndex].parent.value}, {nodeList[nodeIndex].leftChild.value}, {nodeList[nodeIndex].rightChild.value}")
    '''

    for nodeIndex in range(1,nodeNum) : # 1번 노드를 제외하고 각 노드의 부모를 출력
        print(nodeList[nodeIndex].parent.value)

