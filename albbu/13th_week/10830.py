def squareMatrix(matrix):
    matrixSize = len(matrix)

    resultMatrix = []

    for i in range(matrixSize):
        rowElements = []
        for j in range(matrixSize):
            element = 0

            for k in range(matrixSize):
                element += matrix[i][k] * matrix[k][j]

            element %= 1000
            rowElements.append(element)

        resultMatrix.append(rowElements)

    return resultMatrix


def muxMatrix(alphaMatrix, bravoMatrix):
    matrixSize = len(alphaMatrix)

    resultMatrix = []

    for i in range(matrixSize):
        rowElements = []
        for j in range(matrixSize):
            element = 0

            for k in range(matrixSize):
                element += alphaMatrix[i][k] * bravoMatrix[k][j]

            element %= 1000
            rowElements.append(element)

        resultMatrix.append(rowElements)

    return resultMatrix


def divideSquareNum(squareNum, matrix):
    global originMatrix

    if squareNum == 1:
        return matrix

    if squareNum == 2:
        return squareMatrix(matrix)

    if (squareNum % 2) == 1:
        return muxMatrix(squareMatrix(divideSquareNum(squareNum // 2, matrix)), originMatrix)

    if (squareNum % 2) == 0:
        return squareMatrix(divideSquareNum(squareNum // 2, matrix))


def printMatrix(matrix):
    matrixSize = len(matrix)

    for i in range(matrixSize):
        for j in range(matrixSize):

            if j == matrixSize - 1:
                print(matrix[i][j])
            else:
                print(matrix[i][j], end=' ')


if __name__ == "__main__":
    nbInput = list(map(int, input().split()))

    matrixSize = nbInput[0]
    squareNum = nbInput[1]

    originMatrix = []

    for i in range(matrixSize):
        row = []

        for j in list(map(int, input().split())):
            row.append(j % 1000)

        originMatrix.append(row)

    answerMatrix = divideSquareNum(squareNum, originMatrix)
    printMatrix(answerMatrix)
