testCase = int(input())
 
for i in range(0,testCase):
    coinNumber = int(input())
    
    weightSum = 0
    
    bossCoin = 2**coinNumber
   
    hostageNumber = (int(coinNumber/2))-1
   
    bossGroup = bossCoin
   
    for k in range(1,coinNumber+1):
        weightSum += 2**k
    for j in range(1,hostageNumber+1) : 
        bossGroup += 2**j
    
    minorGroup = weightSum - bossGroup
    
    testOutput = bossGroup - minorGroup
 
    print(testOutput)
