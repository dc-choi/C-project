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
	Up and Down
	
	1 ~ 100 사이의 숫자를 임의로 생성하고 그 숫자를 맞추기	
	*/
	
	srand(time(NULL));

	int num = rand() % 100 + 1; // +1을 하여 1 ~ 100 사이의 숫자 생성
	printf("number: %d\n", num); // 정상적으로 생성되는지 디버깅

	int answer = 0;
	int chance = 5;

	while (chance > 0) {
	    printf("남은 기회 %d 번\n", chance--);
	    printf("\n숫자를 맞춰보세요. (1 ~ 100) : ");
	    scanf("%d", &answer);

	    if (answer > num) {
		printf("\nDown\n\n");	
	    } else if (answer < num) {
		printf("\nUp\n\n");
	    } else {
		printf("\n정답입니다.\n");
		break;
	    }

	    if (chance == 0) {
		printf("모든 기회를 다 사용하였습니다. 탈락입니다.\n");
	    }
	}

	return 0;
}
