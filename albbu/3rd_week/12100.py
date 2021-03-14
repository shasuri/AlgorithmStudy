import copy

def printBoard(gameBoard) : # 현재 보드 상태 출력, 정답과는 상관없음
	print("---------------------------------")
	for i in range(len(gameBoard)) :
		for j in range(len(gameBoard)) :
			print(f"{gameBoard[i][j]}  ",end='')
		print("")

def getMaxScore(gameBoard) : #최댓값 구하기
	
	maxScore = 0
	
	for verticSpace in range(len(gameBoard)) :
	
		for horizenSpace in range(len(gameBoard)) :
	
			if gameBoard[verticSpace][horizenSpace] > maxScore :
				maxScore = gameBoard[verticSpace][horizenSpace]

	return maxScore

def moveVertical(gameBoard, xPoint, yPoint, moveVector) : # UP OR DOWN일 경우

	movingSpace = '' # 선 선언
	moveDirection = int(moveVector/abs(moveVector)) # 방향만 알려주는 단위 벡터

	if moveVector < 0 and yPoint+moveVector < 0 : # 리스트 초과 방지
		return gameBoard
	 
	if moveVector > 0 and yPoint+moveVector > len(gameBoard) - 1 : # 리스트 초과 방지
		return gameBoard
	
	selectedSpace = gameBoard[yPoint][xPoint] # 숫자를 움직여 도착할 칸
	movingSpace = gameBoard[yPoint+moveVector][xPoint] # 움직일 숫자가 있을 칸

	if selectedSpace != movingSpace :
		if selectedSpace == 0 : # 숫자가 0을 통해 통과 할경우
			gameBoard[yPoint][xPoint] = movingSpace
			gameBoard[yPoint+moveVector][xPoint] = 0

		elif selectedSpace != 0 and movingSpace != 0 : # 숫자가 다른 숫자와 충돌할 경우
			gameBoard[yPoint+moveDirection][xPoint] = movingSpace

			if yPoint+moveVector != yPoint+moveDirection : # 숫자가 이전에 있던 칸 비우기 단, 충돌지점에선 유지
				gameBoard[yPoint+moveVector][xPoint] = 0 

			return gameBoard

	else :
		if selectedSpace != 0 : # 숫자가 합쳐질 경우
			gameBoard[yPoint][xPoint] *= 2
			gameBoard[yPoint+moveVector][xPoint] = 0

			return gameBoard

	gameBoard = moveVertical(gameBoard,xPoint,yPoint,moveVector+moveDirection) # 벡터를 1만큼 늘려서 재귀

	return gameBoard


def moveHorizental(gameBoard, xPoint, yPoint, moveVector) : #LEFT OR RIGHT일 경우, 나머지는 moveVertical과 동일

	movingSpace = ''
	moveDirection = int(moveVector/abs(moveVector))

	if moveVector < 0 and xPoint+moveVector < 0 :
		return gameBoard
	 
	if moveVector > 0 and xPoint+moveVector > len(gameBoard) - 1 :
		return gameBoard
	
	selectedSpace = gameBoard[yPoint][xPoint]
	movingSpace = gameBoard[yPoint][xPoint+moveVector]

	if selectedSpace != movingSpace :
		if selectedSpace == 0 :
			gameBoard[yPoint][xPoint] = movingSpace
			gameBoard[yPoint][xPoint+moveVector] = 0

		elif selectedSpace != 0 and movingSpace != 0 :
			gameBoard[yPoint][xPoint+moveDirection] = movingSpace

			if yPoint+moveVector != yPoint+moveDirection :
				gameBoard[yPoint][xPoint+moveVector] = 0

			return gameBoard

	else :
		if selectedSpace != 0 :
			gameBoard[yPoint][xPoint] *= 2
			gameBoard[yPoint][xPoint+moveVector] = 0

			return gameBoard

	gameBoard = moveHorizental(gameBoard,xPoint,yPoint,moveVector+moveDirection)


	
	return gameBoard

def moveLine(gameBoard, moveDirection) : # moveVertical, moveHorizen을 구분, 반복
	
	for lineIndex in range(len(gameBoard)) : # 다른 행 / 열로 넘어가기

		if moveDirection == 0 : #UP
			for verticIndex in range(len(gameBoard)) : # 같은 열의 각 칸을 이동
				gameBoard = moveVertical(gameBoard, lineIndex, verticIndex, 1)

		elif moveDirection == 1 : #DOWN
			for verticIndex in range(len(gameBoard)) :
				gameBoard = moveVertical(gameBoard, lineIndex, len(gameBoard)-verticIndex-1, -1)
		
		elif moveDirection == 2 : #LEFT
			for horizenIndex in range(len(gameBoard)) : # 같은 행의 각 칸을 이동
				gameBoard = moveHorizental(gameBoard, horizenIndex, lineIndex, 1)
		
		elif moveDirection == 3 : #RIGHT
			for horizenIndex in range(len(gameBoard)) :
				gameBoard = moveHorizental(gameBoard, len(gameBoard)-horizenIndex-1, lineIndex, -1)

	return gameBoard


if __name__ == "__main__" :
	boardSpace = int(input())

	gameBoard = []
	maxScore = 0

	for verticBoardInput in range(boardSpace) : # 보드 상태 입력
		verticBoardState = input().split()
		
		for cvtIndex in range(len(verticBoardState)) :
			verticBoardState[cvtIndex] = int(verticBoardState[cvtIndex])
				
		gameBoard.append(verticBoardState)
	
	originGameBoard = copy.deepcopy(gameBoard) # 보드를 다른 메모리에 복사
	
	for a in range(4) :
		for b in range(4) :
			for c in range(4) :
				for d in range(4) :
					for e in range(4) :
						gameBoard = moveLine(moveLine(moveLine(moveLine(moveLine(gameBoard,e),d),c),b),a) # 4^5의 경우의 수 이행
						
						highScore = getMaxScore(gameBoard) # 최종 상태의 보드의 최대 값 산출
						
						if maxScore < highScore : #최댓값 비교
							maxScore = highScore

						gameBoard = copy.deepcopy(originGameBoard) # 저장된 보드 불러오기

	print(maxScore)
