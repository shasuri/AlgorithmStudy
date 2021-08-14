
testCase = int(input())

for i in range(testCase):
    slices = int(input())
    minutes = 0
    part = slices % 10

    if(slices < 7):
        minutes += 15
        print(minutes)
        continue

    minutes += (slices // 10) * 25 + (5 * ((slices % 10 + 1) // 2))

    print(minutes)
