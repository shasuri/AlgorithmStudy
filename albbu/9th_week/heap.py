class singleQueue :
    def __init__(self) :
        self.index = None
        self.key = None
        #return self

    def setIndex(self,_index) :
        self.index = _index
        return self

    def setKey(self,_key) :
        self.key = _key
        return self
    
    def getIndex(self) : return self.index

    def getKey(self) : return self.key


class heapTree :
    def __init__(self,_queueList) :
        self.queueList = _queueList
        #return self

    def getHeap(self) : return self.queueList

    def printHeap(self) :
        for i in range(len(self.queueList)) :
            print(f"{i+1} : {self.queueList[i].index} - {self.queueList[i].key}")

    def insertQueue(self,_queue) :

        self.queueList.append(_queue)
        queueIndex = len(self.queueList)

        while True :

            parentIndex = int(queueIndex/2)

            if queueIndex == 1 or _queue.key >= self.queueList[parentIndex-1].key :
                break
            
            self.queueList[queueIndex-1] = self.queueList[parentIndex-1]
            self.queueList[parentIndex-1] = _queue

            queueIndex = parentIndex

        return self.queueList


    def popQueue(self) :
        
        if len(self.queueList) == 0 :
            return self.queueList
        
        outQueue = self.queueList[0]

        lastIndex = 1
        changeIndex = 2 

        self.queueList.insert(lastIndex-1,self.queueList.pop())

        while changeIndex <= len(self.queueList) :
            
            if changeIndex < len(self.queueList) and (self.queueList[changeIndex-1].key > self.queueList[changeIndex].key) :
                changeIndex += 1
            
            if self.queueList[lastIndex-1].key <= self.queueList[changeIndex-1].key :
                break
            
            temp = self.queueList[lastIndex-1]
            self.queueList[lastIndex-1] = self.queueList[changeIndex-1]
            self.queueList[changeIndex-1] = temp

            lastIndex = changeIndex

            changeIndex *= 2

        return outQueue
