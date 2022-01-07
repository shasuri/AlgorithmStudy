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


def searchPattern(pattern,string) :

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
			
	return (searchCounter)


	
if __name__ == "__main__" :

	#child_char = ['r','R','s','e','E','f','a','q','Q','t','T','d','w','W','c','z','x','v','g']
	child_char = "rRseEfaqQtTdwWczxvg"
	#parent_char = ['k','o','i','O','j','p','u','P','H','y','n','b','m','l']
	parent_char = "koiOjpuPhynbml"
	except_char = "EQW"
	#twin_char = ["rt","sw","sg","fr","fa","fq","ft","fx","fv","qt"]
	
	fir_twin_char = "rsfq"
	#fir_twin_char = ['r','s','f','q']

	sec_twin_char = [["t"],["w","g"],["r","a","q","t","x","v","g"],["t"]]

	input_str = input()

	cvt_str = ""
	twin_checker = -1
	
	for cvt_index in range(len(input_str)) :
		
		if twin_checker > -1:
			twin_checker = -1
			continue

		cvt_char = input_str[cvt_index]

		if cvt_char == " " :
			cvt_str += "3"

		elif cvt_char in parent_char :			
			cvt_str += "0"
			twin_checker = -1
		
		else:
			twin_checker = fir_twin_char.find(cvt_char)

			if twin_checker > -1 and cvt_index < len(input_str)-1:
				
				if input_str[cvt_index+1] in sec_twin_char[twin_checker] :
					cvt_str += "21"
				
				elif input_str[cvt_index+1] in parent_char :
					cvt_str += "10"
				
				else :
					cvt_str += "1"
					twin_checker = -1
			
			elif cvt_char in except_char :
				cvt_str += "31"
			
			else :
				cvt_str += "1"

	cvt_str = cvt_str.replace("00","0")

	grace_fire = 0
	grace_fire += searchPattern("1010",cvt_str) + searchPattern("10210",cvt_str)
	

	print(grace_fire)
