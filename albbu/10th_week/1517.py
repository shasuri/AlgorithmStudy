
def mergeSort(array) : # 병합 정렬, 배열 쪼개기

    if len(array) <= 1: # 배열의 길이가 1보다 작을 때 쪼개지 않고 return
        return array
    
    middlePoint = len(array) // 2
    leftSide = array[:middlePoint]
    rightSide = array[middlePoint:]

    leftSide = mergeSort(leftSide) # 왼쪽, 오른쪽 배열을 각각 재귀
    rightSide = mergeSort(rightSide)

    return mergeArray(leftSide,rightSide) # 최종적으로 나온 배열길이가 1인 배열들을 병합하는 것으로 시작

def mergeArray(leftSide,rightSide) :
    global swapCount

    leftIndex = 0
    rightIndex = 0

    tempArray = [] # 병합된 배열

    while (leftIndex < len(leftSide)) and (rightIndex < len(rightSide)) : # 어느 한쪽의 데이터를 다 넣었을 때 반복문 끝
        
        if leftSide[leftIndex] <= rightSide[rightIndex] : # 왼쪽의 첫 원소가 작을 때
            tempArray.append(leftSide[leftIndex])
            leftIndex += 1
            
        else : # 왼쪽의 첫 원소가 작을 때
            tempArray.append(rightSide[rightIndex])
            rightIndex += 1

            swapCount += len(leftSide) - leftIndex # Inversion Counting, 오른쪽 원소를 넣을 때 왼쪽의 남은 원소의 갯수만큼 swap이 발생한다고 판단
    
    while (leftIndex < len(leftSide)) : # 오른쪽의 데이터를 다 읽었을 때, 남은 원소 전부 다 결과 배열에 넣기, 이때 왼쪽배열은 다 정렬되어 있는 상태
        tempArray.append(leftSide[leftIndex])
        leftIndex += 1

    while (rightIndex < len(rightSide)) :
        tempArray.append(rightSide[rightIndex])
        rightIndex += 1

    return tempArray # 결과 배열 return
            

if __name__ == "__main__" :
    arrayNum = int(input())

    array = list(map(int,input().split()))

    swapCount = 0 # 버블소트의 swap 횟수를 세어줄 변수

    sortedArray = mergeSort(array)
    
    print(swapCount)
