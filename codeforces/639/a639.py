testCases = int(input())

for i in range(0,testCases) :
    inputElements = input().split()
    row = int(inputElements[0])
    col = int(inputElements[1])

    if row == 1 or col == 1:
        print("YES")
    elif row == 2 and col == 2:
        print("YES")
    else:
        print("NO")


