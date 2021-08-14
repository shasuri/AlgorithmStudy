
if __name__ == "__main__" :
    novemberKilo = input().split()

    thingNum = int(novemberKilo[0])
    availWeight = int(novemberKilo[1])

    deltaPapa = [[0 for dpIndex in range(availWeight+1)] for dpIndex in range(thingNum+1)]
    
    weightList = [0]
    valueList = [0]

    finalValue = []

    for thingIndex in range(thingNum) :
        whiskeyVictor = input().split()

        thingWeight = int(whiskeyVictor[0])
        thingValue = int(whiskeyVictor[1])

    
        weightList.append(thingWeight)
        valueList.append(thingValue)
    
    for thingIndex in range(thingNum) :
        for weightIndex in range(availWeight) :
            #print(thingIndex+1)
            deltaPapa[thingIndex+1][weightIndex+1] = deltaPapa[thingIndex][weightIndex+1]

            if weightIndex + 1 - weightList[thingIndex+1] >= 0 :
                betterWay = max(deltaPapa[thingIndex+1][weightIndex+1], deltaPapa[thingIndex][weightIndex+1-weightList[thingIndex+1]] + valueList[thingIndex+1])
                deltaPapa[thingIndex+1][weightIndex+1] = betterWay
                #print(betterWay)
                #print(deltaPapa[thingNum][availWeight])
        # for i in deltaPapa[thingIndex+1] :
        #     print(i,end=" ")
        # print("")
    
    print(deltaPapa[thingNum][availWeight])
    