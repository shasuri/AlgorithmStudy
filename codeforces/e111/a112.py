testCase = int(input())

for i in range(testCase) : 
    answer = 0
    sum = int(input())
    value = 1
    value_sum = value
    i = 1

    while(1) :
        if(value_sum >= sum) :
            break
        
        
        value += 2
        value_sum += value

        i += 1

    answer = i

    print(answer)
