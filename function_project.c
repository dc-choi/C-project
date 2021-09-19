#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomNumber(int level);
void showQuestion(int level, int x, int y);
void success();
void fail();

int main(void) {
	
	// scanf_s는 Visual studio에서만 제공하는 비표준 함수라함.
	// scanf_s를 사용하는 이유는 버퍼오버플로우를 막기 위함.
	// scanf를 안전하게 사용하기위해 1열의 #define _CRT_SECURE_NO_WARNINGS를 사용함.
	// _s가 없는것이 _s가 매핑된다고 함.
	
	/*
	GuGuDan Master
	
	문제가 5개가 있고, 각 문제마다 점점 어려운 수식 퀴즈가 출제
	맞히면 통과 틀리면 실패
	*/
	
	srand(time(NULL));

	int count = 0; // 맞춘 개수 저장하는 변수
	
	for (int i = 1; i <= 5; i++) {
	    int x = getRandomNumber(i);
	    int y = getRandomNumber(i);

	    showQuestion(i, x, y);

	    int answer = -1;
	    scanf("%d", &answer);

	    if (answer == -1) {
		printf("프로그램을 종료합니다.\n");
		exit(0); // 바로 종료
	    } else if (answer == x * y) {
		success();
		count++;
	    } else {
		fail();
	    }
	}

	printf("\n\n 당신은 5개의 문제중 %d 개를 맞혔습니다.\n", count);

	return 0;
}

int getRandomNumber(int level) {
    return rand() % (level * 8) + 1;
}

void showQuestion(int level, int x, int y) {
    printf("\n\n\n ########## %d 번째 문제 ##########\n", level);
    printf("\n\t %d X %d 는?\n\n", x, y);
    printf("####################\n");
    printf("\n정답을 입력하세요 (종료 : -1) >> ");
}

void success() {
    printf("정답입니다.\n");
}

void fail() {
    printf("오답입니다.\n");
}
