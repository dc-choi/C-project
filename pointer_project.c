#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int level; // 시간이 지나면서 늘어나는 변수
int arrayFish[6]; // 물고기
int * cursor; // User가 지정하는 물고기

void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
int checkFish();

int main(void) {
	
	
	// Windows에서 clock()은 벽시간을 나타내지만, 
	// Linux에서는 CPU 시간을 나타내서 CPU가 돌아가는 시간만 측정한다.
	// Windows에서 실습을 하고 다시 리눅스로 공부하기 때문에 clock()을 사용했다가 3시간동안 삽질했다...
	// 그래서 원래 time()을 사용하는 부분은 clock()을 사용하고
	// Windows에서 총 경과시간을 구하는 알고리즘은 (clock() - startTime) / CLOCKS_PER_SEC다.
	// Windows랑 달리 time()은 1900년 0시 0분 0초부터 지금까지 흐른 시간을 초단위로 반환.
	// https://korbillgates.tistory.com/100로 좀 더 공부해야함.

	/*
	물고기가 6마리가 있어요.
	이들은 어항에서 살고 있는데, 사막이에요.
	사막이 너무 더워서, 너무 건조해서 물이 아주 빨리 증발을 해요.
	물이 다 증발하기 전에 부지런히 어항에 물을 줘서 물고기를 살려주세요.
	물고기가 죽지않으면 시간이 지날수록 점점 커져서 먹을 수 있습니다.
	*/
	
	long startTime = 0; // 게임 시작 시간
	long totalElapsedTime = 0; // 총 경과시간
	long prevElapsedTime = 0; // 직전 경과시간

	int num;
	initData();

	cursor = arrayFish;

	startTime = time(NULL);
	// printf("디버깅 코드 : startTime : %ld\n", startTime);

	while (1) {
	    printfFishes();
	    printf("몇 번 어항에 물을 주시겠어요? ");
	    scanf("%d", &num);

	    if (num < 1 || num > 6) {
		printf("1 ~ 6 사이의 값을 입력해주세요.\n");
		continue;
	    }

	    totalElapsedTime = time(NULL) - startTime;
	    printf("총 경과 시간 : %ld 초\n", totalElapsedTime);
	    // printf("디버깅 코드 : time(NULL) : %ld\n", time(NULL));
	    // printf("디버깅 코드 : time(NULL) - startTime : %ld\n", time(NULL) - startTime);
	    
	    prevElapsedTime = totalElapsedTime - prevElapsedTime;
	    printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);

	    decreaseWater(prevElapsedTime);

	    if (cursor[num - 1] <= 0) {
		printf("%d 번 물고기는 이미 죽었습니다.\n", num);
	    } else if (cursor[num - 1] <= 100) {
		cursor[num - 1] += 1;
		printf("%d 번 어항에 물을 준다.\n", num);
	    }

	    if (totalElapsedTime / 20 > level - 1) {
		if (level == 5) {
		    printf("\n\n 축하합니다. 최고레벨을 달성하였습니다. 게임을 종료합니다.\n");
		    exit(0);
		} else if (level < 5) {
		    level++;
		    printf("\n\n *** 축 레벨업! 기존 %d 레벨에서 %d 레벨로 변경 되었습니다. *** \n\n" , level - 1, level);
		}
	    }

	    if (checkFish() == 0) {
		printf("\n\n 모든 물고기가 죽었습니다. 게임을 종료합니다.\n");
		exit(0);
	    } else {
		printf("물고기가 아직 살아있습니다. 계속 진행하세요\n");
	    }

	    prevElapsedTime = totalElapsedTime;

	}
	
	return 0;
}

void initData() {
    level = 1;
    for (int i = 0; i < 6; i++) {
	arrayFish[i] = 100;
    }
}

void printfFishes() {
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번 \n", 1, 2, 3, 4, 5, 6);

    for (int i = 0; i < 6; i++) {
	printf(" %d  ", arrayFish[i]);
    }
    printf("\n\n");
}

void decreaseWater(long elapsedTime) {
    for (int i = 0; i < 6; i++) {
	arrayFish[i] -= (level * (int)elapsedTime);
	if (arrayFish[i] < 0) {
	    arrayFish[i] = 0;
	}
    }
}

int checkFish() {
    for (int i = 0; i < 6; i++) {
	if (arrayFish[i] > 0) {
	    return 1;
	}
    }
    return 0;
}

