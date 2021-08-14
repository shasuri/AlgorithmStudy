if __name__ == "__main__":
    caseNum = int(input())
    #caseList = []
    alphaBase = 65
    alphaSum = 0

    alphaList = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    leadList = []

    for caseIndex in range(caseNum):

        alphaStr = input()

        # caseList.append(alphaStr)

        for alphaIndex in range(len(alphaStr)):

            alphaList[ord(alphaStr[alphaIndex]) -
                      alphaBase] += 10 ** (len(alphaStr) - alphaIndex - 1)

        leadList.append(ord(alphaStr[0])-alphaBase)

    # print(alphaList)
    if min(alphaList) == 0:

        alphaList.sort(reverse=True)

        for alphaIndex in range(len(alphaList)):

            alphaSum += alphaList[alphaIndex] * (9 - alphaIndex)

        print(alphaSum)

    else:
        mulList = [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1]
        mulCount = 9
        cvtCount = 1

        for cvtIndex in range(len(alphaList)):
            maxAlpha = 0
            maxIndex = -1

            for mulIndex in range(len(alphaList)):

                if mulList[mulIndex] == -1 and alphaList[mulIndex] > maxAlpha:

                    maxAlpha = alphaList[mulIndex]
                    maxIndex = mulIndex

            mulList[maxIndex] = mulCount
            mulCount -= 1

        while True:
            zeroIndex = mulList.index(0)
            swapIndex = mulList.index(cvtCount)

            if zeroIndex in leadList:
                mulList[zeroIndex], mulList[swapIndex] = mulList[swapIndex], mulList[zeroIndex]
                cvtCount += 1

            else:
                break

        for alphaIndex in range(len(alphaList)):

            alphaSum += alphaList[alphaIndex] * mulList[alphaIndex]

        print(alphaSum)
