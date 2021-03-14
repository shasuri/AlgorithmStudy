import copy

def printRoomState(roomState) :
	
	print("---------------------------------")

	for i in range(len(roomState)) :
		for j in range(len(roomState[0])) :
			print(f"{roomState[i][j]} ",end='')
		print("")

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

def setCameraAlpha(roomState,Xpoint,Ypoint,line) :
	roomState = observeOneWay(roomState,Xpoint,Ypoint,line)
	return roomState


def setCameraBravo(roomState,Xpoint,Ypoint,line) :
	if line == 0 :
		roomState = observeOneWay(roomState,Xpoint,Ypoint,0)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,1)
	if line == 1 :
		roomState = observeOneWay(roomState,Xpoint,Ypoint,2)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,3)

	return roomState


def setCameraCharlie(roomState,Xpoint,Ypoint,line) :
	if line == 0 :
		roomState = observeOneWay(roomState,Xpoint,Ypoint,0)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,2)
	if line == 1 :
		roomState = observeOneWay(roomState,Xpoint,Ypoint,0)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,3)
	if line == 2 :
		roomState = observeOneWay(roomState,Xpoint,Ypoint,1)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,2)
	if line == 3 :
		roomState = observeOneWay(roomState,Xpoint,Ypoint,1)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,3)

	return roomState


def setCameraDelta(roomState,Xpoint,Ypoint,line) :
	if line == 0 :
		roomState = observeOneWay(roomState,Xpoint,Ypoint,0)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,1)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,2)
	if line == 1 :
		roomState = observeOneWay(roomState,Xpoint,Ypoint,0)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,1)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,3)
	if line == 2 :
		roomState = observeOneWay(roomState,Xpoint,Ypoint,0)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,2)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,3)
	if line == 3 :
		roomState = observeOneWay(roomState,Xpoint,Ypoint,1)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,2)
		roomState = observeOneWay(roomState,Xpoint,Ypoint,3)

	return roomState

	
def setCameraEcho(roomState,Xpoint,Ypoint) :
	roomState = observeOneWay(roomState,Xpoint,Ypoint,0)
	roomState = observeOneWay(roomState,Xpoint,Ypoint,1)
	roomState = observeOneWay(roomState,Xpoint,Ypoint,2)
	roomState = observeOneWay(roomState,Xpoint,Ypoint,3)

	return roomState

def checkSpace(roomState,cameraLocation,cameraIndex,checkIndex) :

	Ypoint = cameraLocation[cameraIndex][0]
	Xpoint = cameraLocation[cameraIndex][1]
	cameraType = roomState[Ypoint][Xpoint]

	#print(f"{cameraIndex},{checkIndex}")

	if cameraType == 1 :
		roomState = setCameraAlpha(roomState,Xpoint,Ypoint,checkIndex)
	if cameraType == 2 :
		roomState = setCameraBravo(roomState,Xpoint,Ypoint,checkIndex)
	if cameraType == 3 :
		roomState = setCameraCharlie(roomState,Xpoint,Ypoint,checkIndex)
	if cameraType == 4 :
		roomState = setCameraDelta(roomState,Xpoint,Ypoint,checkIndex)
	if cameraType == 5 :
		roomState = setCameraEcho(roomState,Xpoint,Ypoint)

	return roomState


def countBlindSpot(roomState) :

	blindSpot = 0

	for YLineIndex in range(len(roomState)) :
		for XLineIndex in range(len(roomState[0])) :
			if roomState[YLineIndex][XLineIndex] == 0 :
				blindSpot += 1

	return blindSpot


def recurv(roomState,originRoomState,cameraLocation,cameraList,cameraIndex) :
	global blindSpot
	
	if blindSpot == 0 :
		return
	
	if cameraIndex > len(cameraList) - 1 :
		
		blindPoint = countBlindSpot(roomState)

		if blindPoint < blindSpot :
			blindSpot = blindPoint
		#printRoomState(originRoomState)
		
		return
	
	for recurvIndex in range(cameraList[cameraIndex]) :
		originRoomState = copy.deepcopy(roomState)
		roomState = checkSpace(roomState,cameraLocation,cameraIndex,recurvIndex)
		#print(f"{cameraIndex},{len(cameraList) - 1}")
		
		recurv(roomState,originRoomState,cameraLocation,cameraList,cameraIndex+1)
		roomState = copy.deepcopy(originRoomState)

		
		

if __name__ == "__main__" :
	
	roomSizeInfo = input().split()
	
	roomYSize = int(roomSizeInfo[0])
	roomXSize = int(roomSizeInfo[1])

	roomState = []
	cameraLocation = []
	cameraList = []

	for YLineIndex in range(roomYSize) :
		
		lineInput = input().split()
		
		for XLineIndex in range(len(lineInput)) :
			
			lineInput[XLineIndex] = int(lineInput[XLineIndex])

			if 0 < lineInput[XLineIndex] < 6 :
				cameraLocation.append([YLineIndex,XLineIndex])
				cameraType = lineInput[XLineIndex]

				if cameraType == 1 or cameraType == 3 or cameraType == 4 :	
					cameraList.append(4)
				if cameraType == 2 :
					cameraList.append(2)
				if cameraType == 5 :
					cameraList.append(1)

		roomState.append(lineInput)

	originRoomState = copy.deepcopy(roomState)

	blindSpot = roomYSize * roomXSize

	recurv(roomState,originRoomState,cameraLocation,cameraList,0)
	
	print(blindSpot)
	