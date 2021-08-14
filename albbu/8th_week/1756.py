if __name__ == "__main__" :
    dnInput = list(map(int,input().split()))

    ovenDepth = dnInput[0]
    pizzaNum = dnInput[1]

    ovenSizes = list(map(int,input().split()))
    
    pizzaSizes = list(map(int,input().split()))
    
    minWidth = None

    for ovenIndex in range(ovenDepth) :
        if ovenIndex == 0 :
            minWidth = ovenSizes[ovenIndex]
        
        if ovenSizes[ovenIndex] < minWidth :
            minWidth = ovenSizes[ovenIndex]
        else :
            ovenSizes[ovenIndex] = minWidth

    pizzaIndex = 0
    lastPizzaLoc = 0

    for ovenIndex in range(ovenDepth) :
        pizzaLoc = ovenDepth - ovenIndex - 1

        if ovenSizes[pizzaLoc] >= pizzaSizes[pizzaIndex] :
            
            if pizzaIndex == pizzaNum - 1 :
                lastPizzaLoc = pizzaLoc+1
                break
            
            pizzaIndex += 1

    print(lastPizzaLoc)
