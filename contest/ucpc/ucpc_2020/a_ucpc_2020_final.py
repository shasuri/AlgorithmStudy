
def printNodeList(nodeList) :
    for i in range(len(nodeList)) :
        print(nodeList[i].parent.value,nodeList[i].value, end=" ")
        print("[",end="")

        for j in range(len(nodeList[i].child)) :
            
            print(nodeList[i].child[j].value, end="")
            if j < len(nodeList[i].child) - 1 :
                print(",",end="")
        
        print("]")

def findValue(nodeList,subject) :
    for nodeIndex in range(len(nodeList)) :
        findIndex = len(nodeList) - nodeIndex - 1
        if nodeList[findIndex].value == subject :
            return findIndex

def findApple(nodeList) :
    appleList = []
    
    for nodeIndex in range(len(nodeList)) :
        if len(nodeList[nodeIndex].child) == 0 :
            appleList.append(nodeList[nodeIndex])
    
    return appleList

def findBranch(nodeList) :
    branchList = []
    
    for nodeIndex in range(len(nodeList)) :
        if len(nodeList[nodeIndex].child) > 1 :
            branchList.append(nodeList[nodeIndex])
    
    return branchList

class node :
    def __init__(self, value) :
        self.value = value
        self.parent = None
        self.child = []
        self.depth = None
    
    def beParent(self, papa) :
        self.parent = papa

    def makeChild(self, charlie) :
        (self.child).append(charlie)

    def getDepth(self) :
        depthOutput = 0
        while True :
            
            if self.parent.value == None :
                return depthOutput
            self = self.parent
            depthOutput += 1
    
    def writeDepth(self, depthInput) :
        self.depth = depthInput

    def getBranchLen(self) :
        depthOutput = 0
        while True :
            self = self.parent
            depthOutput += 1
            if self.value == None or len(self.child) > 1 :
                return depthOutput

if __name__ == "__main__" :

    nsdInfo = input().split()

    nodeNum = int(nsdInfo[0])
    kenyLocationS = int(nsdInfo[1])
    powerD = int(nsdInfo[2])

    nodes = []
    branches = []
    path = 0

    root = node(None)

    pathInput = input().split()

    parentValue = int(pathInput[0])
    childValue = int(pathInput[1])

    parentNode = node(parentValue)
    childNode = node(childValue)

    parentNode.beParent(root)
    parentNode.makeChild(childNode)
    childNode.beParent(parentNode)

    nodes.append(parentNode)
    nodes.append(childNode)
    
    for nodeIndex in range(nodeNum-2) :
        pathInput = input().split()

        parentValue = int(pathInput[0])
        childValue = int(pathInput[1])

        childNode = node(childValue)
        
        parentIndex = findValue(nodes,parentValue)
        
        childNode.beParent(nodes[parentIndex])
        nodes[parentIndex].makeChild(childNode)

        if len(nodes[parentIndex].child) > 1 : 
            print(nodes[parentIndex].getDepth())
            path += nodes[parentIndex].getDepth()
        
        nodes.append(childNode)

    #printNodeList(nodes)

    apples = findApple(nodes)

    
    for appleIndex in apples :
        print(appleIndex.getBranchLen())
        path += appleIndex.getBranchLen()
        path -= powerD

    print(path*2)