import fractions
import math
# ab % k = ((a*10**b.len) % k + b % k) % k

def encourage(bitByVisit,depth,rest,lenSum):

    if (depth >= nInput):   # 최종 깊이에 다왔을때
        if (rest == 0):
            return 1        # 나머지가 0이면 1 추가
        else :
            return 0        # 나머지가 있으면 추가 안함
    
    if dp[bitByVisit][rest] != None :   # 기록된 DP면
        return dp[bitByVisit][rest]     # DP의 값 반환
    else :
        dp[bitByVisit][rest] = 0        # 기록되지 않았으면, None을 0으로 바꿔서 기록표기

    for index,element in enumerate(permSet) :
        # if used[index] == False : # bit DP
            # used[index] = True
        if bitByVisit&(1<<index) == 0:  # bit DP, 사용한 정수인지 검증, 사용안했으면 0
            dp[bitByVisit][rest] += encourage(
                bitByVisit|(1<<index),  # index번째 정수를 사용했음을 bit에 표기
                depth+1,
                (remained[index][lenSum] + rest) % kInput,  # ab % k
                lenSum + lenSet[index]  # 숫자가 채워질 자리
            )
            
            # used[index] = False

    return dp[bitByVisit][rest]

if __name__ == "__main__":
    nInput = int(input())   # N입력

    permSet = []    # 정수들을 담을 list
    lenSet = []     # 정수의 자릿수를 담을 list

    for i in range(nInput):
        elemInput = input()
        
        permSet.append(int(elemInput))  # 정수 입력
        lenSet.append(len(elemInput))

    kInput = int(input())   # K입력

    for index,element in enumerate(permSet):
        permSet[index] = element % kInput   # 정수들에 미리 MOD 연산적용, 1500ms차

    permCount = math.factorial(nInput)      # 전체 순열 갯수
    ansCount = 0                            # 나머지 0인 순열 갯수

    dp=[[None]*kInput for x in range(2**nInput)]            # 정답갯수를 담아둘 DP, dp[방문순열][나머지]
    remained = [[None]*sum(lenSet) for x in range(nInput)]  # 나머지를 저장할 배열, remained[선택한정수][증가한자릿수]
    
    # visited = [False for x in range(nInput)]        # bit DP

    for i in range(nInput) :
        for j in range(sum(lenSet)) :
            remained[i][j] = (permSet[i] * 10 ** j) % kInput    # remained에 각 정수의 k 나머지 입력

    encourage(0,0,0,0)  # bitDP = 0, depth = 0, rest = 0, 자릿수 = 0

    ansCount = dp[0][0] # 재귀함수로 dp[0][0]에 모든순열의 정답여부의 합이 저장
    
    if ansCount == permCount :
        print("1/1")    # fractions.Fraction 예외처리

    elif ansCount == 0:
        print("0/1")    # fractions.Fraction 예외처리
    else :
        print(fractions.Fraction(ansCount,permCount))   # 분수 출력
