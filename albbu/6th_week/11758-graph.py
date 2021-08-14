import fractions

if __name__ == "__main__" :
    
    firstPoint = input().split()
    secondPoint = input().split()
    thirdPoint = input().split()

    firstX = int(firstPoint[0])
    firstY = int(firstPoint[1])

    secondX = int(secondPoint[0])
    secondY = int(secondPoint[1])

    thirdX = int(thirdPoint[0])
    thirdY = int(thirdPoint[1])

    firstDeltaY = secondY - firstY
    firstDeltaX = secondX - firstX
   
    secondDeltaY = thirdY - secondY
    secondDeltaX = thirdX - secondX

    if firstDeltaX == 0 : 
        rotateDirection = firstDeltaY * secondDeltaX * -1
    else :
        leftSide = thirdY
        rightSide = ((firstDeltaY * thirdX) + (firstDeltaX * firstY) - (firstDeltaY * firstX)) / firstDeltaX
        #print(leftSide,rightSide)

        graphDirection = leftSide - rightSide

        rotateDirection = firstDeltaX * graphDirection

    if rotateDirection > 0 :
        print(1)
    if rotateDirection == 0 :
        print(0)
    if rotateDirection < 0 :
        print(-1)