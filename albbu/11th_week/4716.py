
class singleTeam:
    def __init__(self, _balloonNum, _alphaDistance, _bravoDistance):
        self.balloonNum = _balloonNum
        self.alphaDistance = _alphaDistance
        self.bravoDistance = _bravoDistance

        self.distances = [self.alphaDistance, self.bravoDistance]
        self.abGap = abs(self.alphaDistance - self.bravoDistance)


def quickSort(teamList):
    if len(teamList) <= 1:
        return teamList

    pivot = teamList[len(teamList) // 2]
    pivotGap = pivot.abGap

    lesserList = []
    equalList = []
    greaterList = []

    for team in teamList:
        element = team.abGap

        if element < pivotGap:
            lesserList.append(team)
        if element > pivotGap:
            greaterList.append(team)
        if element == pivotGap:
            equalList.append(team)

    return quickSort(greaterList) + equalList + quickSort(lesserList)


if __name__ == "__main__":
    while(True):
        nabInput = list(map(int, input().split()))

        teamNum = nabInput[0]

        if teamNum == 0:
            break

        alphaBalloon = nabInput[1]
        bravoBalloon = nabInput[2]

        balloons = [alphaBalloon, bravoBalloon]

        teamList = []

        for i in range(teamNum):
            kdInput = list(map(int, input().split()))
            teamList.append(singleTeam(kdInput[0], kdInput[1], kdInput[2]))

        teamList = quickSort(teamList)

        minDistance = 0

        for team in teamList:

            if team.alphaDistance <= team.bravoDistance:
                wayIndex = 0
            else:
                wayIndex = 1

            if balloons[wayIndex] < team.balloonNum:
                team.balloonNum -= balloons[wayIndex]
                minDistance += balloons[wayIndex] * team.distances[wayIndex]
                balloons[wayIndex] = 0

                wayIndex = int(not(wayIndex))

            balloons[wayIndex] -= team.balloonNum
            minDistance += team.balloonNum * team.distances[wayIndex]
            team.balloonNum = 0

        print(minDistance)
