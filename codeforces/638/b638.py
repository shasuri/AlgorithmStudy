testCases = int(input())

for i in range(0,testCases):
    inputElements = input().split()
    arLen = int(inputElements[0])
    sarLen = int(inputElements[1])
    
    beauAr = input().split()
    
    impChk = list(set(beauAr))

    if len(impChk) > sarLen :
        print(-1)
    
    else:
        perAr = list(set(beauAr))
       
        for a in range(0,sarLen-len(impChk)):
            perAr.append('1')
        
        perAr=perAr*100
        print(len(perAr))
        for p in perAr :
            print(p,end=' ')
        print('')
