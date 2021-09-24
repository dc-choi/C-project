#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arrayAnimal[4][5]; // 카드 지도수
int checkAnimal[4][5]; // 뒤집혔는지 여부 확인
char * strAnimal[10]; // 동물을 종류별로 저장하는 변수

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPostion();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestions();
int foundAllAnimal();

int main(void) {
	
	/*
	10마리의 서로 다른 동물 (각 카드 2장씩)
	사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
	모든 동물 상을 찾으면 게임 종료
	총 실패 횟수 알려주기
	*/

	srand(time(NULL));
	
	initAnimalArray();
	initAnimalName();

	shuffleAnimal();

	int failCount = 0; // 실패 횟수

	while (1) {
	    int select1 = 0; // 사용자가 선택하는 처음 수
	    int select2 = 0; // 사용자가 선택하는 다음 수

	    printAnimals();
	    printQuestions();

	    printf("\n\n뒤집을 카드를 2개 고르세요.\n\n");
	    printf("첫번째 뒤집을 카드를 고르세요.\n");
	    scanf("%d", &select1);
	    printf("두번째 뒤집을 카드를 고르세요.\n");
	    scanf("%d", &select2);

	    if (select1 == select2) // 같은 카드 선택 시 무효
		continue;
	    
	    // 정수 좌표를 (x, y)로 변환
	    int firstSelect_x = conv_pos_x(select1);
	    int firstSelect_y = conv_pos_y(select1);

	    int secondSelect_x = conv_pos_x(select2);
	    int secondSelect_y = conv_pos_y(select2);

	    if ((checkAnimal[firstSelect_x][firstSelect_y] == 0 && checkAnimal[secondSelect_x][secondSelect_y] == 0) // 카드가 뒤집히지 않았는지
	    && arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y]) { // 두 동물이 같은지
		printf("\n\n빙고!! : %s 발견\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
		checkAnimal[firstSelect_x][firstSelect_y] = 1;
		checkAnimal[secondSelect_x][secondSelect_y] = 1;
		printf("%d", checkAnimal[firstSelect_x][firstSelect_y]);
		printf("%d", checkAnimal[secondSelect_x][secondSelect_y]);
	    } else {
		printf("\n\n 땡!! \n\n");
		printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
		printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
		printf("\n\n");

		failCount++;
	    }

	    if (foundAllAnimal() == 1) {
		printf("\n\n 축하합니다. 모든 동물을 다 찾았네요. \n");
		printf("지금까지 총 %d 번 실수를 하셨습니다.\n", failCount);
		break;
	    }
	}
	
	return 0;
}


void initAnimalArray() {
    printf("동물지도 초기 세팅중...\n");
    for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 5; j++) {
	    arrayAnimal[i][j] = -1;
	}
    }
}

void initAnimalName() {
    printf("동물이름 초기 세팅중...\n");
    strAnimal[0] = "원숭이";
    strAnimal[1] = "하마";
    strAnimal[2] = "강아지";
    strAnimal[3] = "고양이";
    strAnimal[4] = "돼지";

    strAnimal[5] = "코끼리";
    strAnimal[6] = "기린";
    strAnimal[7] = "낙타";
    strAnimal[8] = "타조";
    strAnimal[9] = "호랑이";
}

void shuffleAnimal() {
    printf("카드를 섞는중입니다... \n");
    for (int i = 0; i < 10; i++) {
	for (int j = 0; j < 2; j++) {
	    int pos = getEmptyPostion();
	    int x = conv_pos_x(pos);
	    int y = conv_pos_y(pos);

	    arrayAnimal[x][y] = i;
	}
    }
}

int getEmptyPostion() {
    while (1) {
	int randPos = rand() % 20;
	int x = conv_pos_x(randPos);
	int y = conv_pos_y(randPos);

	if (arrayAnimal[x][y] == -1) {
	    return randPos;
	}
    }
    return 0;
}

int conv_pos_x(int x) {
    return x / 5;
}

int conv_pos_y(int y) {
    return y % 5;
}

void printAnimals() {
    printf("\n\n 원래 알려주면 안돼는데 걍 보여드릴게! \n\n\n");
    for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 5; j++) {
	    printf("|");
	    printf("%8s", strAnimal[arrayAnimal[i][j]]);
	    printf("|");
	}
	printf("\n");
    }
}

void printQuestions() {
    printf("\n\n (문제) \n");

    int seq = 0;

    for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 5; j++) {
	    if (checkAnimal[i][j] != 0) {
		printf("|");
		printf("%8s", strAnimal[arrayAnimal[i][j]]);
		printf("|");
	    } else {
		printf("%8d", seq);
	    }
	    seq++;
	}
	printf("\n");
    }
}

int foundAllAnimal() {
    for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 5; j++) {
	    if (checkAnimal[i][j] == 0) {
		return 0;
	    }
	}
    }
    return 1;
}

