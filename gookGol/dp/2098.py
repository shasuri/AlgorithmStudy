import math

def travel(presentLocation,bitFootPrint) :

    # print(presentLocation,bitFootPrint)
    if dp[presentLocation][bitFootPrint] > 0 :
        return dp[presentLocation][bitFootPrint]

    if bitFootPrint == fullPrint :
        # return dp[presentLocation][bitFootPrint]
        # return dp[presentLocation][bitFootPrint] + cost[presentLocation][startLocation]
        if cost[presentLocation][0] == 0 :
            return math.inf
        else :
            return cost[presentLocation][0]

    minCost = math.inf

    for dst in range(cityNum):
        tmp = 0
        if bitFootPrint & (1 << dst) == 0 :
            if cost[presentLocation][dst] == 0 :
                continue

            tmp += travel(
                dst,
                bitFootPrint | (1 << dst)
            ) + cost[presentLocation][dst]

            if tmp < minCost :
                minCost = tmp
    
    dp[presentLocation][bitFootPrint] = minCost

    return minCost


if __name__ == "__main__" :
    
    cityNum = int(input())
    
    cost = []
    
    fullPrint = (1 << cityNum) - 1
    pathSize = (2 ** (cityNum))
    dp = [[0] * pathSize for x in range(cityNum)]
    

    for i in range(cityNum) :
        cost.append(list(map(int,input().split())))

    print(travel(0,1))

# ((0 | (1 << 1)) | (1 << 3))


