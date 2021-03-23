import copy
import fractions

def makeItPos(baseStr, elements):

    for i in range(len(elements)) :
        temp = elements[i]

        tempElems = copy.deepcopy(elements)

        tempElems.remove(tempElems[i])
        makeItPos(baseStr + temp,tempElems)
    
    if(len(elements) == 0):
        global permCount
        permCount += 1

        if (int(baseStr) % kInput == 0):
            global ansCount
            ansCount += 1


if __name__ == "__main__":
    nInput = int(input())

    permSet = []

    setCases = []

    for i in range(nInput):
        permSet.append(input())

    kInput = int(input())

    permCount = 0
    ansCount = 0


    makeItPos("",permSet)
    
    ansProb = fractions.Fraction(ansCount,permCount)
    print(str(ansProb.numerator)+"/"+str(ansProb.denominator))

    # ansCount = 

    
