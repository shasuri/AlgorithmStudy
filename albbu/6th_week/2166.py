
def getScale(alphaPoint,bravoPoint,charliePoint) :

    scale = (bravoPoint[0]-alphaPoint[0])*(charliePoint[1]-alphaPoint[1]) - (bravoPoint[1]-alphaPoint[1])*(charliePoint[0]-alphaPoint[0])

    # scale = abs(scale) / 2

    return scale

if __name__ == "__main__" :
    pointNum = int(input())

    pointList = []

    totalScale = 0

    for pointIndex in range(pointNum) :
        pointInput = input().split()

        for elementIndex in range(2) :
            pointInput[elementIndex] = int(pointInput[elementIndex])

        pointInput = tuple(pointInput)
        pointList.append(pointInput)

    
    for triangleIndex in range(pointNum-2) :
        # print(pointList[0],pointList[triangleIndex+1],pointList[triangleIndex+2])
        totalScale += getScale(pointList[0],pointList[triangleIndex+1],pointList[triangleIndex+2])
        print(totalScale)
        
    totalScale = abs(totalScale) / 2
    totalScale = round(totalScale,1)

    print(totalScale)
