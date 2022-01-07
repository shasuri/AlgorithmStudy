from math import sqrt

testCases = int(input())

for i in range(0,testCases) :
    givenStick = float(input())
    
    yourTower = 0
    while(1) :
        towerFloor = int(sqrt((givenStick*2)/3+(1/36))-(1/6)+0.0000001)
     
        usedStick = towerFloor*(3*towerFloor+1)/2

        leftStick = givenStick - usedStick
        
        givenStick = leftStick

        if(towerFloor > 0) :
            yourTower += 1
        else :
            break
        
    print(yourTower)

    

