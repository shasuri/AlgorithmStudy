
class trie:
    def __init__(self, string):
        self.children = {}
        self.string = string

    def addChild(self, childChar):
        if not(childChar in self.children):
            self.children[childChar] = trie(self.string)
        return self.children[childChar]

    def traceChild(self, traceChar):
        if self.children.get(traceChar, False) == False:
            return False
        else:
            return self.children[traceChar]


def addChildrenXt(addTrie, addChar):
    return addTrie.addChild(addChar)


def traceChildrenXt(traceTrie, traceChar):
    return traceTrie.traceChild(traceChar)


if __name__ == "__main__":

    nmInput = list(map(int, input().split()))
    rootTrie = trie('')
    ans = 0

    for i in range(nmInput[0]):
        setString = input() + '.'

        addRoot = rootTrie
        for c in setString:
            addRoot = addChildrenXt(addRoot, c)

    for i in range(nmInput[1]):
        checkString = input() + '.'

        checker = True
        traceRoot = rootTrie
        for c in checkString:
            traceRoot = traceChildrenXt(traceRoot, c)

            if traceRoot == False:
                checker = False
                break

        if checker:
            ans += 1

    print(ans)
