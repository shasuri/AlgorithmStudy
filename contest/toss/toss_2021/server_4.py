"""
2021 토스 NEXT 개발자로 입사하게된 김토스는 유저들을 위해 홈 화면에 유용한 금융 정보를 보여주기로 했습니다.
유용한 정보라도 너무 자주 보여주면 유저들에게 불편함을 줄 수 있어, 빈도를 조절하여 적절히 노출하려 합니다.

다음과 같은 방법으로 노출을 결정하는 코드를 작성해 주세요.

유용한 금융정보는 하루에 여러 번 노출 될 수 있습니다.
M일 동안 N회 노출이 되었거나 유저가 거부하면, 더 이상 노출하지 않으며, 다음날부터 M일까지 유용한 금융 정보를 노출하지 않습니다.
입력 및 출력
첫 줄에는 M N이 입력되고, M N을 출력합니다.

0 < M < 10000
0 < N < 100000
두 번째 줄부터는 각 이벤트에 따른 명령이 주어지고, 명령에 따라 결과를 출력합니다.

명령	출력	설명
SHOW	1 또는 0	노출을 시도합니다. 노출되었으면 1 그렇지 않으면 0
NEGATIVE	0	노출을 거부합니다.
NEXT	-	다음날로 날짜를 변경합니다.
EXIT	BYE	BYE 를 출력하고 종료합니다.
만약 규격에 맞지 않는 줄 입력이 들어오는 경우, 이 줄은 무시하고 ERROR 를 출력합니다.
다음 입력을 계속 처리할 수 있다면 계속 처리하고, 그렇지 않다면 종료합니다.

데이터 포맷
입력은 여러줄의 문자열로, 각 줄의 앞뒤 공백은 없으며,
출력 마지막에는 줄변경 문자열이 들어가지 않습니다.
줄구분 문자열은 \n을 사용합니다.

만약 입력이 아래와 같다면

1 3 
SHOW
NEXT
EXIT
문자열 1 3\nSHOW\nNEXT\nEXIT으로 들어 오며,

출력이 아래와 같다면

1 3
1
-
BYE
문자열 1 3\n1\n-\nBYE을 반환해야 합니다.

입출력 예시
예시 0
INPUT	OUTPUT
1 2	1 2
SHOW	1
SHOW	1
NEXT	-
SHOW	0
NEXT	-
SHOW	1
NEXT	-
SHOW	1
EXIT	BYE
예시 1
INPUT	OUTPUT
2 2	2 2
SHOW	1
SHOW	1
NEXT	-
SHOW	0
NEXT	-
SHOW	0
NEXT	-
SHOW	1
EXIT	BYE
예시 2
INPUT	OUTPUT
2 3	2 3
SHOW	1
SHOW	1
NEXT	-
SHOW	1
SHOW	0
NEXT	-
SHOW	0
NEXT	-
SHOW	0
SHOW	0
NEXT	-
SHOW	1
EXIT	BYE
예시 3
INPUT	OUTPUT
2 3	2 3
SHOW	1
NEGATIVE	0
SHOW	0
NEXT	-
SHOW	0
SHOW	0
NEXT	-
SHOW	0
NEXT	-
SHOW	1
SHOW	1
NEXT	-
SHOW	1
SHOW	0
EXIT	BYE
예시 4
INPUT	OUTPUT
1 3	1 3
SHOW	1
HELLO	ERROR
EXIT	BYE
"""
