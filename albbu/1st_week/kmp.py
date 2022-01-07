def getPatternIndex(pattern) :

	patternIndex = [0] * len(pattern)

	secondIndex = 0

	for firstIndex in range(1,len(pattern)) :

		while secondIndex > 0 and pattern[firstIndex] != pattern[secondIndex] :
			
			secondIndex = patternIndex[secondIndex-1]

		if pattern[firstIndex] == pattern[secondIndex] :

			secondIndex += 1
			
			patternIndex[firstIndex] = secondIndex
				
	return patternIndex

def searchPattern() :

	pattern = "1010"
	string = "10101010"

	patternList = getPatternIndex(pattern)
	
	searchCounter = 0

	stringIndex = 0
	patternIndex = 0

	for stringIndex in range(len(string)):

		while patternIndex > 0 and string[stringIndex] != pattern[patternIndex] :
			patternIndex = patternList[patternIndex-1]

		if string[stringIndex] == pattern[patternIndex] :
			
			if patternIndex == len(pattern) - 1 :
				searchCounter += 1

				patternIndex = patternList[patternIndex]
			else :
				patternIndex += 1

		stringIndex += 1
			
	print(searchCounter)

searchPattern()
