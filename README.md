# calculaotr-Clang

C언어로 만든 간단한 사칙연산 계산기

현재 문저점은 기호를 입력하는 칸에 1바이트를 초과하는 값으 입력하게 되면 오버플로우가 일어나 특정 문장이 반복해서 출력됨

char를 이용해 사칙연산 기호(+, -, /, *)를 입력받아 계산함

short르 사용해 숫자를 입력받아 switch문을 통해 특수기호와 연결 시키는 방법이 더 안정적일 거 같음
