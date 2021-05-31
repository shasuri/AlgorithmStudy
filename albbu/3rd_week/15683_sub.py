import copy
from itertools import permutations

def printRoomState(roomState) :
	
	print("---------------------------------")

	for i in range(len(roomState)) :
		for j in range(len(roomState[0])) :
			print(f"{roomState[i][j]} ",end='')
		print("")


def countOpenWay(roomState,Xpoint,Ypoint) :
	roomWidth = len(roomState[0])
	roomLength = len(roomState)
	openWay = 4
	# print(f"x : {Xpoint}")

	if Xpoint-1 < 0 :
		openWay -= 1
	elif roomState[Ypoint][Xpoint-1] == 6 :
		openWay -= 1

	if Xpoint+1 > roomWidth - 1 :
		openWay -= 1
	elif roomState[Ypoint][Xpoint+1] == 6 :
		openWay -= 1

	if Ypoint-1 < 0 :
		openWay -= 1
	elif roomState[Ypoint-1][Xpoint] == 6 :
		openWay -= 1

	if Ypoint+1 > roomLength - 1 :
		openWay -= 1
	elif roomState[Ypoint+1][Xpoint] == 6 :
		openWay -= 1

	return openWay


def observeY(roomState,Xpoint,Ypoint,direction,mode) :
	
	roomLength = len(roomState)
	observeSpot = 0
	directIndex = 0

	while -1 < Ypoint + direction + directIndex < roomLength :
		spot = roomState[Ypoint + direction + directIndex][Xpoint]

		if spot == 0 :
			observeSpot += 1
			if mode == 1 :
				roomState[Ypoint + direction + directIndex][Xpoint] = '#'
		
		if spot == 6 :
			break
		
		directIndex += direction

	if mode == 0 :
		return observeSpot

	if mode == 1 :
		return roomState


def observeX(roomState,Xpoint,Ypoint,direction,mode) :
	
	roomWidth = len(roomState[0])
	observeSpot = 0
	directIndex = 0

	while -1 < Xpoint + direction + directIndex < roomWidth :
		spot = roomState[Ypoint][Xpoint + direction + directIndex]

		if spot == 0 :
			observeSpot += 1
			if mode == 1 :
				roomState[Ypoint][Xpoint + direction + directIndex] = '#'
		
		if spot == 6 :
			break
		
		directIndex += direction

	if mode == 0 :
		return observeSpot

	if mode == 1 :
		return roomState


def observeFourWay(roomState,Xpoint,Ypoint) :
	observeLines = []

	observeLines.append(observeX(roomState,Xpoint,Ypoint,1,0)) # LEFT
	observeLines.append(observeX(roomState,Xpoint,Ypoint,-1,0)) # RIGHT
	observeLines.append(observeY(roomState,Xpoint,Ypoint,1,0)) # UP
	observeLines.append(observeY(roomState,Xpoint,Ypoint,-1,0)) # DOWN

	return observeLines


def observeOneWay(roomState,Xpoint,Ypoint,observeLine) :
	
	if observeLine == 0 :
		roomState = observeX(roomState,Xpoint,Ypoint,1,1)

	if observeLine == 1 :
		roomState = observeX(roomState,Xpoint,Ypoint,-1,1)

	if observeLine == 2 :
		roomState = observeY(roomState,Xpoint,Ypoint,1,1)

	if observeLine == 3 :
		roomState = observeY(roomState,Xpoint,Ypoint,-1,1)

	return roomState

def setCamera(roomState,Xpoint,Ypoint) :
	cameraType = roomState[Ypoint][Xpoint]

	observeLines = observeFourWay(roomState,Xpoint,Ypoint)

	maxSpace = -1
	chosenLine = 0

	if cameraType == 1 :
		
		for observeIndex in range(4) :
		
			if observeLines[observeIndex] > maxSpace :
		
				maxSpace = observeLines[observeIndex]
				chosenLine = observeIndex
		
		roomState = observeOneWay(roomState,Xpoint,Ypoint,chosenLine)
		
	if cameraType == 2 :
		
		if observeLines[0] + observeLines[1] > observeLines[2] + observeLines[3] :
			roomState = observeOneWay(roomState,Xpoint,Ypoint,0)
			roomState = observeOneWay(roomState,Xpoint,Ypoint,1)
		else :
			roomState = observeOneWay(roomState,Xpoint,Ypoint,2)
			roomState = observeOneWay(roomState,Xpoint,Ypoint,3)

	if cameraType == 3 :

		if observeLines[0] > observeLines[1] :
			roomState = observeOneWay(roomState,Xpoint,Ypoint,0)
			if observeLines[2] > observeLines[3] :
				roomState = observeOneWay(roomState,Xpoint,Ypoint,2)
			else :
				roomState = observeOneWay(roomState,Xpoint,Ypoint,3)
		
		else :
			roomState = observeOneWay(roomState,Xpoint,Ypoint,1)
			if observeLines[2] > observeLines[3] :
				roomState = observeOneWay(roomState,Xpoint,Ypoint,2)
			else :
				roomState = observeOneWay(roomState,Xpoint,Ypoint,3)

	if cameraType == 4 :
		maxSpace = 9

		for observeIndex in range(4) :

			if observeLines[observeIndex] < maxSpace :
				maxSpace = observeLines[observeIndex]
				chosenLine = observeIndex

			chosenList = list(range(4))
			chosenList.remove(chosenLine)

			#print(chosenList)

			for chooseIndex in chosenList :
				roomState = observeOneWay(roomState,Xpoint,Ypoint,chooseIndex)
	
	if cameraType == 5 :
		roomState = observeOneWay(roomState,Xpoint,Ypoint,0)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,1)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,2)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,3)

	return roomState

# def checkAllOrder(roomState,cameraLocation,orderList) :

# 	while checkIndex < len(cameraLocation) :
# 		if cameraLocation[checkIndex] in orderList :
# 			pass
# 		else :
# 			orderList.append(cameraLocation[checkIndex])
		
# 			if len(orderList) >= len(cameraLocation) :
# 				for orderIndex in orderList :
# 					roomState = setCamera(roomState,cameraLocation[1],cameraLocation[0])
# 				return countBlindSpot(roomState)

# 			else :
# 				blindSpot = checkAllOrder(roomState,cameraLocation,orderList)
# 				orderList.pop()
# 				checkIndex += 1

# 	return blindSpot

def countBlindSpot(roomState) :

	blindSpot = 0

	for YLineIndex in range(len(roomState)) :
		for XLineIndex in range(len(roomState[0])) :
			if roomState[YLineIndex][XLineIndex] == 0 :
				blindSpot += 1

	return blindSpot

def listSetCamera(roomState,cameraLocation) :

	for setIndex in range(len(cameraLocation)) :
		roomState = setCamera(roomState,cameraLocation[setIndex][1],cameraLocation[setIndex][0])
	
	blindSpot = countBlindSpot(roomState)
	return blindSpot

def perm(arr, depth, n, roomState):
    # depth가 0부터 시작하여 k라면 k개를 모두 뽑은 것이므로 print하고 return
    global blindSpot
    global originRoomState
    roomState = copy.deepcopy(originRoomState)
    if (depth == n):
        blindPoint = listSetCamera(roomState,arr)
        #print(blindPoint)
        
        if blindPoint < blindSpot :
        	blindSpot = blindPoint

        return
    for idx in range(depth, n):
        # 각 depth에 대해 남아 있는 것들 중에 모두 뽑아보고,
        # 해당 경우에 대해 재귀적으로 perm 함수를 돌리고,
        # 원상복구 하여 다시 경우의 수를 찾는다
        arr[idx], arr[depth] = arr[depth], arr[idx]
        perm(arr, depth+1, n,roomState)
        if blindSpot == 0 :
        	return
        arr[idx], arr[depth] = arr[depth], arr[idx]

    #return

if __name__ == "__main__" :
	
	roomSizeInfo = input().split()
	
	roomYSize = int(roomSizeInfo[0])
	roomXSize = int(roomSizeInfo[1])

	roomState = []
	cameraLocation = []

	for YLineIndex in range(roomYSize) :
		
		lineInput = input().split()
		
		for XLineIndex in range(len(lineInput)) :
			
			lineInput[XLineIndex] = int(lineInput[XLineIndex])

			if 0 < lineInput[XLineIndex] < 6 :
				cameraLocation.append([YLineIndex,XLineIndex])

		roomState.append(lineInput)

	originRoomState = copy.deepcopy(roomState)
	blindSpot = roomYSize * roomXSize
	perm(cameraLocation,0,len(cameraLocation),roomState)

	print(blindSpot)
	