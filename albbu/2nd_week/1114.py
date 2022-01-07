def absol(num) :
	
	if num < 0 :
		num = num * -1
	
	return num

if __name__ == "__main__" :
	
	lkcInput = input().split()

	logLength = int(lkcInput[0])
	cutLocationNum = int(lkcInput[1])
	cutNum = int(lkcInput[2])

	locationInput = input().split()

	for splitIndex in range(cutLocationNum) :
		locationInput[splitIndex] = int(locationInput[splitIndex])

	logStart = 0
	logEnd = logLength
	firstLogLength = logLength
	cuttingIndex = 0
	
	logList = [[logStart,logEnd,logLength]]

	for cutIndex in range(cutNum) :
		chkLocate = False

		for chkIndex in range(cutLocationNum) :
			if logStart < locationInput[splitIndex] < logEnd:
				chkLocate = not(chkLocate)
		
		if chkLocate :
			break

		minGap = firstLogLength + 1
		minIndex = cutLocationNum + 1
		
		for splitIndex in range(cutLocationNum) :

			if logStart < locationInput[splitIndex] < logEnd :
				gap = absol(locationInput[splitIndex] - (logStart + (logLength / 2)))

				if gap < minGap :
					minGap = gap
					minIndex = splitIndex
			
				# elif gap == minGap and locationInput[minIndex] > locationInput[splitIndex] :
				# 	minGap = gap
				# 	minIndex = splitIndex

		cuttingLocation = locationInput[minIndex]
		
		if cutIndex == 0 :
			firstCuttingLocation = cuttingLocation

		firstLength = cuttingLocation - logStart
		secondLength = logEnd - cuttingLocation

		# print(logList)
		logList.pop(cuttingIndex)
		logList.append([logStart, cuttingLocation, firstLength])
		logList.append([cuttingLocation, logEnd, secondLength])

		maxLength = 0
		maxLenIndex = len(logList)
		
		for maxIndex in range(len(logList)) :
			if logList[maxIndex][2] > maxLength :
				
				maxLenIndex = maxIndex
				maxLength = logList[maxIndex][2]

		logLength = logList[maxLenIndex][2]
		logStart = logList[maxLenIndex][0]
		logEnd = logList[maxLenIndex][1]
		cuttingIndex = maxLenIndex

		# print(logList)
		# print(cuttingIndex)
		
	print(f"{logLength} {firstCuttingLocation}")
