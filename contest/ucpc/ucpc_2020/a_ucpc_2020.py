if __name__ == "__main__" :
    formulaInput = input().split()

    alpha = int(formulaInput[0])
    bravo = int(formulaInput[1])
    charlie = int(formulaInput[2])
    delta = int(formulaInput[3])
    echo = int(formulaInput[4])
    foxtrot = int(formulaInput[5])

    yankee = int(((alpha*foxtrot) - (delta * charlie)) / ((alpha * echo) - (delta*bravo)))

    if alpha != 0 :
        xray = int((charlie - (bravo*yankee)) / alpha)
    else :
        xray = int(((bravo*foxtrot) - (echo*charlie)) / ((delta*bravo) - (alpha*echo)))

    print(f"{xray} {yankee}")