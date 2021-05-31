if __name__ == "__main__" :
    treeNum = int(input())
    trees = input().split()

    treeHeiSum = 0
    oneCount = 0
    oddCount = 0

    for treeIndex in range(len(trees)) :
        trees[treeIndex] = int(trees[treeIndex])
        if trees[treeIndex] == 3 :
            trees[treeIndex] = 0
        treeHeiSum += trees[treeIndex]
        if trees[treeIndex] == 1 :
            oneCount += 1
        elif trees[treeIndex] % 2 == 1 :
            oddCount += 1
        #if trees[treeIndex] % 3 == 0 :


    if treeHeiSum % 3 != 0 :
        print("NO")

    else :
        if oneCount > 0 :
            oneCount += oddCount
            if treeHeiSum - oneCount >= oneCount * 2 :
                print("YES")
            else :
                print("NO")
        else :
            print("YES")


        