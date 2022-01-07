from math import inf


class node :
    def __init__(self,_num) :
        self.nodeNum = _num
        self.lineList = []
        
    def addLine(self,_destination,_value) :
        self.lineList.append((_destination,_value))


class singleQueue :
    def __init__(self,_key) :
        self.key = _key
        self.routeValue = inf
        self.preNodeNum = None

    def setRouteValue(self,_value) :
        self.routeValue = _value

    def setPreNodeNum(self,_num) :
        self.preNodeNum = _num


def printHeap(heap) :
    for nodeIndex in range(len(heap)) :
        print(f"{heap[nodeIndex].key} : {heap[nodeIndex].routeValue}")
    print("----------")


def makeHeap(nodes,startPoint) : 
    heap = []
    
    for nodeIndex in nodes :
        queue = singleQueue(nodeIndex.nodeNum)
        heap.append(queue)
    
    heap[startPoint-1].setRouteValue(0)
    
    heap.insert(0,heap.pop(startPoint-1))
    
    return heap


def insertQueue(heap,queue) :
    
    heap.append(queue)
    queueIndex = len(heap) - 1

    while True :
        
        parentIndex = int((queueIndex+1)/2) - 1
        
        if (queueIndex+1 == 1) or (queue.routeValue >= heap[parentIndex].routeValue) :
            break
        
        temp = queue
        heap[queueIndex] = heap[parentIndex]
        heap[parentIndex] = queue

        queueIndex = parentIndex

    return heap


def popQueue(heap) :
    
    queuePoped = heap[0]
    
    lastIndex = 0
    if len(heap) == 1 :
        heap.insert(0,None)
    
    heap[lastIndex] = heap.pop()

    childIndex = 1

    while childIndex <= len(heap)-1 :
        if childIndex < len(heap)-1 and (heap[childIndex].routeValue > heap[childIndex+1].routeValue) :
            childIndex += 1
        
        if heap[lastIndex].routeValue <= heap[childIndex].routeValue :
            break
        
        temp = heap[lastIndex]
        heap[lastIndex] = heap[childIndex]
        heap[childIndex] = temp

        lastIndex = childIndex
        
        childIndex *= 2
        childIndex += 1

    return queuePoped, heap


def getRoute(nodes,startPoint) :
    
    heap = makeHeap(nodes,startPoint)
    
    distanceList = [inf for x in range(len(nodes))]
    distanceList[startPoint-1] = 0

    while True :

        minQueue, heap = popQueue(heap)
    
        if minQueue.routeValue == inf :
            break

        minIndex = minQueue.key - 1
        
        if distanceList[minIndex] >= minQueue.routeValue : 
            
            lines = nodes[minIndex].lineList

            for lineIndex in lines :
                destination = lineIndex[0]
                value = lineIndex[1]

                if distanceList[destination-1] > minQueue.routeValue + value :
                    
                    distanceList[destination-1] = minQueue.routeValue + value
                    
                    queueInsert = singleQueue(destination)
                    queueInsert.setRouteValue(distanceList[destination-1])
                    queueInsert.setPreNodeNum(minQueue.key)
                    
                    heap = insertQueue(heap,queueInsert)
                    
    return distanceList

    
if __name__ == "__main__" :
    veInput = list(map(int,input().split()))

    nodeNum = veInput[0]
    lineNum = veInput[1]

    startNodeNum = int(input())

    nodeList = []
    
    for nodeIndex in range(nodeNum) :
        nodeList.append(node(nodeIndex+1))

    for lineIndex in range(lineNum) :
        uvwInput = list(map(int,input().split()))
        
        sourceNode = uvwInput[0]
        destinationNode = uvwInput[1]
        value = uvwInput[2]

        nodeList[sourceNode-1].addLine(destinationNode,value)

    minDistances = getRoute(nodeList,startNodeNum)

    for minIndex in minDistances :
        
        if minIndex == inf :
            print("INF")
        else :
            print(minIndex)
