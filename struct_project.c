#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
5마리의 고양이가 있다.
아무 키나 눌러서 랜덤으로 고양이를 뽑되,
5마리 모두 다 수집을 해서 열심히 키우면 되는 게임!
중 복 발 생 가 능 !
*/

// 고양이
typedef struct {
    char * name; // 이름
    int age; // 나이
    char * character; // 성격
    int level; // 키우는 난이도
} CAT;

// 전체 고양이
CAT cats[5];

// 현재까지 보유한 고양이
int collection[5] = {0, 0, 0, 0, 0};

void initCat(); // 고양이 정보 초기화
void printCat(int selected); // 고양이 정보 출력
int checkCollection(); // 고양이 결과 체크

int main(void) {
    
    srand(time(NULL));

    initCat();

    while (1) {
	printf("\n\n 두근두근~! 어느 고양이의 집사가 될까요? \n 아무키나 눌러서 확인하세요!\n");
	getchar();

	int selected = rand() % 5; // 0~4 사이 숫자 반환
	printCat(selected);
	collection[selected] = 1;
	int collectALL = checkCollection();

	if (collectALL) {
	    printf("\n\n --- 축하합니다! 모든 고양이를 다 모았습니다~~ --- \n\n");
	    break;
	}
    }

    return 0;
}

void initCat() {
    cats[0].name = "순둥이";
    cats[1].name = "깜냥이";
    cats[2].name = "길냥이";
    cats[3].name = "까칠이";
    cats[4].name = "성난이";

    cats[0].age = 5;
    cats[1].age = 7;
    cats[2].age = 3;
    cats[3].age = 1;
    cats[4].age = 2;

    cats[0].character = "순함";
    cats[1].character = "검은 고양이";
    cats[2].character = "유기묘";
    cats[3].character = "까칠함";
    cats[4].character = "까칠하고 성남";

    cats[0].level = 1;
    cats[1].level = 2;
    cats[2].level = 3;
    cats[3].level = 4;
    cats[4].level = 5;
}

void printCat(int selected) {
    printf("\n\n --- 당신은 이 고양이의 집가사 되었어요! --- \n\n");
    printf("이름 :%s\n", cats[selected].name);
    printf("나이 : %d\n", cats[selected].age);
    printf("특징 : %s\n", cats[selected].character);
    printf("난이도 : ");
    for (int i = 0; i < cats[selected].level; i++) {
	printf("%s", "★");
    }
    printf("\n");
}

int checkCollection() {
    int collectALL = 1;

    for (int i = 0; i < 5; i++) {
	if (collection[i] == 0) {
	    printf("%10s", "(빈 박스)");
	    collectALL = 0;
	} else {
	    printf("%10s", cats[i].name);
	}
    }

    return collectALL;
}
