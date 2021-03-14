
def rotateGear(gearState, direction) :
	if direction == 1 : # rotating clock direction
		gearState = [gearState[7]] + gearState[0:7]

	elif direction == -1 : # rotating un-clock direction
		gearState = gearState[1:8] + [gearState[0]]

	return gearState


def cycleGear(gearNum, direction, gears) :
	rotateCheck = [0,0,0,0] # decide rotate or not list

	rotateCheck[gearNum] += direction # given gear rotate by given direction

	originGearNum = gearNum
	originDirection = direction

	if gearNum > 0 : # rotating gear proceeding to left
		
		for cycleIndex in range(gearNum) :		
			
			if gears[gearNum][6] != gears[gearNum-1][2] and gearNum > 0 :
				
				direction *= (-1) # change the direction
				rotateCheck[gearNum-1] += direction

				gearNum -= 1 # proceed to left gear
		
			else :
				break
	
	gearNum = originGearNum
	direction = originDirection

	if gearNum < 3 : # rotating gear proceeding to right

		for cycleIndex in range(3 - gearNum) :

			if gears[gearNum][2] != gears[gearNum+1][6] and gearNum < 3  :

				direction *= (-1) # change the direction
				rotateCheck[gearNum+1] += direction
				
				gearNum += 1 # proceed to right gear
		
			else :
				break

	# print(f"rotation : {rotateCheck}")

	for rotatingIndex in range(len(rotateCheck)) :
		
		if rotateCheck[rotatingIndex] != 0 :
		
			gears[rotatingIndex] = rotateGear(gears[rotatingIndex], rotateCheck[rotatingIndex]) # rotate gears refer to 'rotateCheck'

	return gears # return all rotated gears list


if __name__ == "__main__" :

	gearList = []

	for gearInputIndex in range(4) :
		singleGear = list(input())

		for gearIndex in range(len(singleGear)) :
			singleGear[gearIndex] = int(singleGear[gearIndex]) # convert strings to integers

		gearList.append(singleGear)
		
		# 3시방향 : 2 / 9시방향 : 6
	
	#print(f"cycle before : {gearList}")

	rotateTimes = int(input())

	for rotateIndex in range(rotateTimes) :
		rotateInput = input().split()

		rotateGearNum = int(rotateInput[0]) - 1 # subtract 1, because match to array number
		rotateDirection = int(rotateInput[1])

		gearList = cycleGear(rotateGearNum, rotateDirection, gearList) # decide given and surrounded gears are rotated or not 
		
		#print(f"cycle {rotateIndex} : {gearList}")

	score = 0
	
	for scoringIndex in range(len(gearList)) :
		score += gearList[scoringIndex][0] * (2 ** scoringIndex) # add the scores

	print(score)
