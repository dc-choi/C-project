#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	
	// scanf_s는 Visual studio에서만 제공하는 비표준 함수라함.
	// scanf_s를 사용하는 이유는 버퍼오버플로우를 막기 위함.
	// scanf를 안전하게 사용하기위해 1열의 #define _CRT_SECURE_NO_WARNINGS를 사용함.
	// _s가 없는것이 _s가 매핑된다고 함.
	
	/*
	별표 피라미드 출력
	
	내가 입력한 정수에 따라 피라미드 모양으로 *을 출력한다.
	입력한 정수에 따라 띄어쓰기를 이용하여 중간정렬을 한다.
	*/
	
	int floor;
	printf("몇층으로 쌓으시겠습니까?\n");
	scanf("%d", &floor);
	
	for (int i = 0; i < floor; i++) {
		for (int j = i; j < floor - 1; j++) {
			printf(" ");
		}
		for (int k = 0; k < i * 2 + 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
