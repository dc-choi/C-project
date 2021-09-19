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
	아빠는 대머리 게임
	
	머리가 나는 발모제를 알아맞추는 게임
	*/
	
	srand(time(NULL));

	printf("\n\n === 아빠는 대머리 게임 === \n\n");

	int answer; // 사용자 입력값
	int treatment = rand() % 4; // 발모제

	int cntShowBottle = 0; // 이번 게임에 보여줄 병 갯수
	int cntPrevShowBottle = 0; // 앞 게임에 보여준 병 갯수
	// 보여주는 병 갯수를 다르게 하여 정답률 향상
	
	// 3번의 기회
	for (int i = 1; i <= 3; i++) {
	    int bottle[4] = {0, 0, 0, 0}; // 4개의 병
	    
	    do {
		cntShowBottle = rand() % 2 + 2; // 2, 3
	    } while (cntShowBottle == cntPrevShowBottle);
	    cntPrevShowBottle = cntShowBottle;

	    int isIncluded = 0; // 보여줄 병 중에 발모제가 포함되었는지 여부
	    printf(" > %d 번째 시도 : ", i);

	    // 보여줄 병 종류를 선택
	    for (int j = 0; j < cntShowBottle; j++) {
		int randBottle = rand() % 4; // 0 ~ 3

		// 아직 선택되지 않은 병이면, 선택처리
		if (bottle[randBottle] == 0) {
		    bottle[randBottle] = 1;
		    if (randBottle == treatment) {
			isIncluded = 1;
		    }
		} else { // 이미 선택된 병이면, 중복이므로 다시 선택
		    j--;
		}
	    }

	    for (int k = 0; k < 4; k++) {
		if (bottle[k] == 1) {
		    printf("%d", k + 1);
		}
	    }

	    printf("\t물약을 머리에 바릅니다.\n\n");

	    if (isIncluded == 1) {
		printf("성공! 머리가 났어요!\n\n");
	    } else {
		printf("실패! 머리가 안났어요!\n\n");
	    }
	}

	printf("\n 발모제는 몇번일까요?\t");
	scanf("%d", &answer);

	if (answer == treatment + 1) {
	    printf("정답!!\n");
	} else {
	    printf("오답!! 정답은 %d 입니다.\n", treatment + 1);
	}

	return 0;
}
