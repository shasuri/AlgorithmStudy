def printLcsBoard(lb,astr,bstr) :
    print("  ",end="")
    for achar in astr :
        print(achar,end=" ")
    print("")

    for yLine in range(len(bstr)) :
        print(bstr[yLine],end=" ")
        for xLine in range(len(astr)) :
            print(lb[yLine][xLine],end=" ")
        print("")
        

if __name__ == "__main__" :
    
    alphaStr = input()
    bravoStr = input()

    lcsBoard = []
    leftUpPoint = 0
    leftPoint = 0
    upPoint = 0

    for yLine in range(len(bravoStr)) :
        rowLine = []
        for xLine in range(len(alphaStr)) :
           
            if xLine - 1 < 0 or yLine - 1 < 0 :
                leftUpPoint = 0
            else :
                leftUpPoint = lcsBoard[yLine-1][xLine-1]
            
            if xLine - 1 < 0 :
                leftPoint = 0
            else :
                leftPoint = rowLine[xLine-1]
            
            if yLine - 1 < 0 :
                upPoint = 0
            else :
                upPoint = lcsBoard[yLine-1][xLine]
            
            if alphaStr[xLine] == bravoStr[yLine] :
                rowLine.append(leftUpPoint + 1)
            
            else : #alphaStr[xLine] != bravoStr[yLine]
                rowLine.append(max(upPoint,leftPoint))

        lcsBoard.append(rowLine)

    print(lcsBoard[-1][-1])

#   a c a y k p
# c 0 1 1 1 1 1
# a 1 1 2 2 2 2
# p 1 1 2 2 2 3
# c 1 2 2 2 2 3 
# a 1 2 3 3 3 3
# k 1 2 3 3 4 4