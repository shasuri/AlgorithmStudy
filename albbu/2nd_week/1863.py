if __name__ == "__main__":

    numChange = input()
    numChange = int(numChange)
    numBuilding = 0

    lowestHeight = 0
    changeList = []

    for changeIndex in range(numChange):

        changePoint = input()
        changePoint = changePoint.split(' ')
        changePoint = list(map(int, changePoint))

        if changePoint[1] > 0:

            if changePoint[1] < lowestHeight:
                lowestHeight = changePoint[1]

            if changePoint[0] > 1:

                if changeList[-1][1] == 0:  # 땅이었다가 건물이 나타날때
                    lowestHeight = changePoint[1]  # 처음나온 건물의 높이를 저장

                if changePoint[1] > changeList[-1][1]:  # 땅/이전 건물보다 높을 떄
                    numBuilding += 1

                if changePoint[1] < changeList[-1][1]:  # 높은 건물에 낮은건물이 숨어있는 경우

                    for checkIndex in range(len(changeList)):

                        if changeList[-1-checkIndex][1] < changePoint[1]:
                            numBuilding += 1
                            break
                        elif changeList[-1-checkIndex][1] == changePoint[1]:
                            break

                        if len(changeList) - checkIndex - 1 == 0:
                            numBuilding += 1

            else:  # 처음 시작 시
                lowestHeight = changePoint[1]
                numBuilding += 1

        #print(f"num : {numBuilding}")

        changeList.append(changePoint)

    print(numBuilding)

'''
 x
 xx x
 xx xx
 xxxxxx
 xxxxxx 
6
1 5
2 4
3 2
4 4
5 3
6 2
5
'''
