if __name__ == "__main__" :
	mnInput = input()
	mnInput = mnInput.split()
	
	myCandy = int(mnInput[0])
	friends = int(mnInput[1])

	friendCandy = []
	rageList = []
	candySum = 0
	rageSum = 0

	for friendIndex in range(friends) :
		reqCandy = int(input())
		
		friendCandy.append(reqCandy)
		rageList.append(0)

		candySum += reqCandy

	rageSource = candySum - myCandy
	
	while rageSource > 0 :
		greedyFriends = friends - friendCandy.count(0)

		divRage = int(rageSource / greedyFriends)

		#print(f"div : {divRage}")
		
		if divRage < 1 :
			divRage = 1

		for subIndex in range(friends) :
			
			if friendCandy[subIndex] == 0 :
				continue

			if friendCandy[subIndex] >= divRage :
				friendCandy[subIndex] -= divRage
				rageList[subIndex] += divRage
				rageSource -= divRage
				
				if rageSource < 1 :
					break

			else :
				subDivRage = friendCandy[subIndex]
				
				friendCandy[subIndex] -= subDivRage
				rageList[subIndex] += subDivRage
				rageSource -= subDivRage

				if rageSource < 1 :
					break
				


	for rageIndex in rageList :
		rageSum += rageIndex ** 2

	#print(f"rageList : {rageList}")
	#print(f"friendCandy : {friendCandy}")
	print(rageSum % (2**64))
