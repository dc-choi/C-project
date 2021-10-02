#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define setSize 256

typedef struct {
    char name[setSize];
    int age;
    double weight;
    double height;
    char content[setSize];
} person;

person scanReports(person p);
void printReports(person p);

int main(void) {
	
    /*
    경찰서 조서 작성
    이름, 나이, 몸무게, 키, 죄명
    */

    // scanf_s는 Visual studio에서만 제공하는 비표준 함수라함.
    // scanf_s를 사용하는 이유는 버퍼오버플로우를 막기 위함.
    // scanf를 안전하게 사용하기위해 1열의 #define _CRT_SECURE_NO_WARNINGS를 사용함.
    // _s가 없는것이 _s가 매핑된다고 함.
	
    person p;
    p = scanReports(p);
    printReports(p);

    return 0;
}

person scanReports(person p) {
    printf("이름\n");
    scanf("%[^\n]", p.name);

    printf("나이\n");
    scanf("%d", &p.age);

    printf("몸무게\n");
    scanf("%lf", &p.weight);

    printf("키\n");
    scanf("%lf", &p.height);

    getchar(); // 입력받기 전 getchar() 함수로 입력버퍼를 비운다.
    printf("니 죄가 뭐야?\n");
    scanf("%[^\n]", p.content);

    return p;
};

void printReports(person p) {
    printf("\n\n -- 범죄 이력 -- \n\n");
    printf("이름 : %s\n", p.name);
    printf("나이 : %d\n", p.age);
    printf("몸무게 : %.2lf\n", p.weight);
    printf("키 : %.2lf\n", p.height);
    printf("범죄명 : %s\n", p.content);
}

