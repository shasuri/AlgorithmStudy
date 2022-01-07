if __name__ == "__main__" :
	resultList = []
	listIndex = 0
	while True :
		
		inputStr = input()
		
		if "-" in inputStr :
			break

		calcCount = 0
		editCount = 0

		for calcIndex in range(len(inputStr)) :
			
			if inputStr[calcIndex] == "{" :
				calcCount += 1
			
			if inputStr[calcIndex] == "}" :
				calcCount -= 1
			
			if calcCount < 0 :
				editCount += 1
				calcCount += 2

		if calcCount > 0 :
			editCount += int(calcCount/2)
		
		listIndex += 1
		result = f"{listIndex}. {editCount}"
		resultList.append(result)

	for resultIndex in resultList :
		print(resultIndex)