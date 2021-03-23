
def testingCase():
    nmInput = tuple(map(int,input().split()))
    
    n = nmInput[0]
    m = nmInput[1]

    return comb(m,n)


if __name__ == "__main__":
    testCaseNum = int(input())

    for i in range(testCaseNum) :
       print(testingCase())
    