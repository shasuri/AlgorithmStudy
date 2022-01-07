class disjointSet:
    def __init__(self, _elementNum):
        self.elementNum = _elementNum
        self.preset = self.makePreset()
        self.setRank = [0 for i in range(self.elementNum)]

    def makePreset(self):
        _preset = []
        for setIndex in range(self.elementNum):
            _preset.append(setIndex)

        return _preset

    def findElement(self, _element):
        if self.preset[_element] == _element:
            return _element

        else:
            self.preset[_element] = self.findElement(self.preset[_element])
            return(self.preset[_element])

    def unionSet(self, _xrayElement, _yankeeElement):

        _xrayElement = self.findElement(_xrayElement)
        _yankeeElement = self.findElement(_yankeeElement)

        if _xrayElement == _yankeeElement:
            return

        if self.setRank[_xrayElement] < self.setRank[_yankeeElement]:
            self.preset[_xrayElement] = _yankeeElement

        else:
            self.preset[_yankeeElement] = _xrayElement

        if self.setRank[_xrayElement] == self.setRank[_yankeeElement]:
            self.setRank[_xrayElement] += 1


if __name__ == "__main__":
    nmInput = list(map(int, input().split()))

    elementNum = nmInput[0] + 1
    calcNum = nmInput[1]

    setTree = disjointSet(elementNum)

    for calcIndex in range(calcNum):
        cabInput = list(map(int, input().split()))

        calcType = cabInput[0]
        alphaElement = cabInput[1]
        bravoElement = cabInput[2]

        if calcType == 0:
            setTree.unionSet(alphaElement, bravoElement)

        if calcType == 1:
            alphaRoot = setTree.findElement(alphaElement)
            bravoRoot = setTree.findElement(bravoElement)

            if alphaRoot == bravoRoot:
                print("YES")
            else:
                print("NO")
