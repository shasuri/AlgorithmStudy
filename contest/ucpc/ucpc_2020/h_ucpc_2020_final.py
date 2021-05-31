#http://mwultong.blogspot.com/2007/03/python-reduce-fraction.html
def gcd(a, b):
  while (b != 0):
    temp = a % b
    a = b
    b = temp
  return abs(a)

def reduceFraction(bunja, bunmo):
  frac = [ bunja, bunmo ]

  if (frac[1] == 0): # 분모가 0일 경우에 에러 반환
    frac[0] = 0
    frac[1] = 0
    return frac

  gcd_result = gcd(frac[0], frac[1])

  frac[0] = frac[0] / gcd_result
  frac[1] = frac[1] / gcd_result

  return frac


def calcCost(startX,startY,endX,endY) :
    global buildCostA
    global wallCostB

    axis = reduceFraction(abs(startX-endX),abs(startY-endY))

    mok = int((startX-endX) / axis[0])

    rowLine = (axis[0] - 1) * mok
    colLine = (axis[1] - 1) * mok

    brokenBuilding = 1 + 1*mok

    return brokenBuilding*buildCostA+(rowLine+colLine)*wallCostB


if __name__ == "__main__" :    
    nmabInput = input().split()
    
    setRowN = int(nmabInput[0])
    setColM = int(nmabInput[1])
    buildCostA = int(nmabInput[2])
    wallCostB = int(nmabInput[3])
    
    cost = 0

    for startX in range(setRowN+1) :
        for startY in range(setColM+1) :
            for endX in range(setRowN+1) :
                for endY in range(setColM+1) :
                    if startX == endX or startY == endY :
                        continue
                    
                    cost += int(calcCost(startX,startY,endX,endY)*2)

    print(cost%(10**9+7))
                    
