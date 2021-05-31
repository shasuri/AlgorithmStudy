class node:
    def __init__(self, value):
        self.value = value
        self.cntNode = []

        self.dfsChk = False
        self.bfsChk = False

    def addNode(self, nodeNum):
        if len(self.cntNode) == 0:
            self.cntNode.append(nodeList[nodeNum-1])

        else:
            for k in range(len(self.cntNode)):
                if self.cntNode[k].value >= nodeNum:
                    self.cntNode.insert(k, nodeList[nodeNum-1])
                    break
            self.cntNode.append(nodeList[nodeNum-1])

    def checkDfs(self):
        self.dfsChk = True

    def checkBfs(self):
        self.bfsChk = True


def dfs(startPoint):
    if startPoint.dfsChk:
        #print("Returned early.")
        return []

    startPoint.checkDfs()

    thisPath = [startPoint.value]

    for j in startPoint.cntNode:
        if not j.dfsChk:
            thisPath += dfs(j)

            if len(thisPath) >= vertexNum:
                #print("Returned early.")
                return thisPath

    return thisPath


def bfs(startPoint):
    startPoint.checkBfs()

    thisPath = [startPoint.value]

    for j in thisPath:
        n = nodeList[j-1]
        for k in n.cntNode:

            if not k.bfsChk:
                k.checkBfs()
                thisPath.append(k.value)

                if len(thisPath) >= vertexNum:
                    return thisPath

    return thisPath


if __name__ == "__main__":
    nmvInput = list(map(int, input().split()))

    vertexNum = nmvInput[0]
    edgeNum = nmvInput[1]
    startVertex = nmvInput[2]

    nodeList = tuple(node(x+1) for x in range(vertexNum))

    for i in range(edgeNum):
        edgeInput = list(map(int, input().split()))

        alphaVertex = edgeInput[0]
        bravoVertex = edgeInput[1]

        nodeList[alphaVertex-1].addNode(bravoVertex)
        nodeList[bravoVertex-1].addNode(alphaVertex)

    dfsResult = dfs(nodeList[startVertex - 1])
    bfsResult = bfs(nodeList[startVertex - 1])

    for d in range(len(dfsResult)):
        if d < len(dfsResult) - 1:
            print(dfsResult[d], end=" ")
        else:
            print(dfsResult[d])

    for b in range(len(bfsResult)):
        if b < len(bfsResult) - 1:
            print(bfsResult[b], end=" ")
        else:
            print(bfsResult[b])

'''
dfs와 bfs의 탐색경로를 찾아내는문제, 재귀에 약해서 기본을 다지려고 풀었다. 정작 bfs는 재귀를 안쓰네??
'''
