class disjointSet:
    def __init__(self):
        self.elementNum = 0
        self.preset = []
        self.setRank = []
        self.friendNum = []

    def appendElement(self):
        self.preset.append(len(self.preset))
        self.setRank.append(0)
        self.friendNum.append(1)

    def findElement(self, _element):
        if self.preset[_element] == _element:
            return _element

        else:
            self.preset[_element] = self.findElement(self.preset[_element])
            return(self.preset[_element])

    def unionSet(self, _xrayElement, _yankeeElement):

        _xrayElement = self.findElement(_xrayElement)
        _yankeeElement = self.findElement(_yankeeElement)

        # print(self.preset) #tester
        # print(f"x : {_xrayElement}") #tester
        # print(f"y : {_yankeeElement}") #tester

        if _xrayElement == _yankeeElement:
            return self.friendNum[_xrayElement]

        friendSum = 0

        if self.setRank[_xrayElement] < self.setRank[_yankeeElement]:
            self.preset[_xrayElement] = _yankeeElement
            self.friendNum[_yankeeElement] += self.friendNum[_xrayElement]
            self.friendNum[_xrayElement] = 1
            friendSum = self.friendNum[_yankeeElement]

        else:
            self.preset[_yankeeElement] = _xrayElement
            self.friendNum[_xrayElement] += self.friendNum[_yankeeElement]
            self.friendNum[_yankeeElement] = 1
            friendSum = self.friendNum[_xrayElement]

        if self.setRank[_xrayElement] == self.setRank[_yankeeElement]:
            self.setRank[_xrayElement] += 1

        return friendSum


if __name__ == "__main__":

    testCaseNum = int(input())
    for testIndex in range(testCaseNum):
        friendRelation = int(input())

        friendSet = disjointSet()

        friendIndex = {}

        for relationIndex in range(friendRelation):
            friends = input().split()

            if friendIndex.get(friends[0]) == None:
                friendIndex[friends[0]] = len(friendIndex)
                friendSet.appendElement()

            if friendIndex.get(friends[1]) == None:
                friendIndex[friends[1]] = len(friendIndex)
                friendSet.appendElement()

            # print(friendIndex) #tester

            alphaFriend = friendIndex.get(friends[0])
            bravoFriend = friendIndex.get(friends[1])

            friendSum = friendSet.unionSet(alphaFriend, bravoFriend)

            # print("Sum : " + str(friendSum)) #tester
            print(friendSum)

        # friendIndex.clear()
        # friendSet = None
