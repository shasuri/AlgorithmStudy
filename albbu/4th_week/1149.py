def printCosts(costList) :
    print("  R  G  B")
    for houseIndex in range(len(costList)) :
        print(houseIndex+1,end=" ")

        for costIndex in costList[houseIndex] :
            print(costIndex,end=" ")
        print("")

if __name__ == "__main__" :
    houseNum = int(input())

    rgbCost = []

    for houseIndex in range(houseNum) :
        costs = input().split()
        
        for costIndex in range(3) :
            
            costs[costIndex] = int(costs[costIndex])
            
            if houseIndex > 0 :
                if costIndex == 0 :
                    costs[costIndex] += min(rgbCost[houseIndex-1][1],rgbCost[houseIndex-1][2])
                if costIndex == 1 :
                    costs[costIndex] += min(rgbCost[houseIndex-1][0],rgbCost[houseIndex-1][2])
                if costIndex == 2 :
                    costs[costIndex] += min(rgbCost[houseIndex-1][0],rgbCost[houseIndex-1][1])

        rgbCost.append(costs)

    #printCosts(rgbCost)
    print(min(rgbCost[-1]))
