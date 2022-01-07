
if __name__ == "__main__" :
	
	ipAdr = input()

	ipList = ipAdr.split(':')

	if len(ipList) > 8 :
		ipList = ipList[:8]


	if len(ipList) < 8 :
		for ipEle in range(len(ipList)) :
			if ipList[ipEle] == '' :
				for insertIndex in range(8-len(ipList)) :
					ipList.insert(ipEle,'')
				break

	for ipIndex in range(len(ipList)) :
		thisIp = ipList[ipIndex]
		
		if len(thisIp) < 4 :
			ipList[ipIndex] = '0'*(4-len(thisIp)) + thisIp

	print(':'.join(ipList))
