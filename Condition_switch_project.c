#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	
	// scanf_s는 Visual studio에서만 제공하는 비표준 함수라함.
	// scanf_s를 사용하는 이유는 버퍼오버플로우를 막기 위함.
	// scanf를 안전하게 사용하기위해 1열의 #define _CRT_SECURE_NO_WARNINGS를 사용함.
	// _s가 없는것이 _s가 매핑된다고 함.
	
	/*
	가위 바위 보
	
	0 ~ 2 사이의 숫자를 임의로 생성하고 그 숫자에 따라 가위 바위 보 프로그램 실행	
	*/
	
	srand(time(NULL));

	int num = rand() % 3; // +1을 하여 1 ~ 100 사이의 숫자 생성
	printf("number: %d\n", num); // 정상적으로 생성되는지 디버깅

	switch (num) {
	    case 0 : printf("가위.\n");
		break;
	    case 1 : printf("바위.\n");
		break;
	    case 2 : printf("보.\n");
		break;
	    default : printf("지정되지 않은 오류입니다.\n");
		break;
	}	

	return 0;
}
