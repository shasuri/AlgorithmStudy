import copy

def harvestFarm(farmState,farmSize,startPoint) :
    direction = 1
    time = 0
    farmerLocation = startPoint
    potato = 0
    crashCount = 0

    while True :
        farmerLocation += direction
        time += 1

        # print(f"locate : {farmerLocation}")
        if farmerLocation > farmSize or farmerLocation < 1 :
            break

        farmObject = farmState[farmerLocation-1]
        # print(farmState)
        # print(F"obj : {farmObject}")
        if farmObject == "P" :
            potato += 1
            farmState[farmerLocation-1] = "."
            direction *= -1

        if farmObject == "R" :
            direction *= -1
            crashCount += 1
            farmState[farmerLocation-1] = "r"
        
        if crashCount > 1 :
            time = -1
            break

        if farmObject == "r" :
            direction *= -1

    # print(f"potato : {potato} time : {time}\n")
    # print(f"{potato} {time}")
    return potato, time

# def escapeFarm(farmState,far,startPoint) :
#     # eastSide = farmState[startPoint-1:]
#     # westSide = farmState[:startPoint]

#     potato = 0

#     eastRock = 0
#     westRock = 0

#     potatoLocation = []
#     rockLocation = []

#     for westIndex in range(1,startPoint-1) :
#         westPoint = startPoint - 1 + westIndex
#         if westPoint < 1 :
#             break
        
#         if farmState[westPoint] == "P" :
#             potato += 1
#             potatoLocation.append(westPoint)
        
#         if farmState[westPoint] == "R" :
#             westRock += 1
#             rockLocation.append(westPoint)
#             break


#     for eastIndex in range(1,farmSize-startPoint) :
#         eastPoint = startPoint - 1 + eastIndex
#         if eastPoint > farmSize :
#             break
        
#         if farmState[eastPoint] == "P" :
#             potato += 1
#             potatoLocation.append(eastPoint)
        
#         if farmState[eastPoint] == "R" :
#             eastRock += 1
#             rockLocation.append(eastPoint)
#             break
    
#     if westRock > 0 and eastRock > 0 :
#         time = -1
#         return
    


if __name__ == "__main__" :
    nqInput = input().split()

    farmSize = int(nqInput[0])
    questionNum = int(nqInput[1])

    farmState = list(input())
    
    originFarm = copy.deepcopy(farmState)
    answerList = []

    for questionIndex in range(questionNum) :
        startPoint = int(input())
        
        potato,time = harvestFarm(farmState,farmSize,startPoint)
        #escapeFarm(farmState,farmSize,startPoint)
        answerList.append([potato,time])
        farmState = copy.deepcopy(originFarm)

    for a in answerList :
        print(f"{a[0]} {a[1]}")
