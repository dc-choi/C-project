#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define setSize 256
int main(void) {
	
	/*
	경찰서 조서 작성
	이름, 나이, 몸무게, 키, 죄명
	*/

	// scanf_s는 Visual studio에서만 제공하는 비표준 함수라함.
	// scanf_s를 사용하는 이유는 버퍼오버플로우를 막기 위함.
	// scanf를 안전하게 사용하기위해 1열의 #define _CRT_SECURE_NO_WARNINGS를 사용함.
	// _s가 없는것이 _s가 매핑된다고 함.
	
	char name[setSize];
	printf("이름\n");
	scanf("%s", name);

	int age;
	printf("나이\n");
	scanf("%d", &age);

	double weight;
	printf("몸무게\n");
	scanf("%lf", &weight);

	double height;
	printf("키\n");
	scanf("%lf", &height);
	
	char content[setSize];
	printf("니 죄가 뭐야?\n");
	scanf("%s", content);
	
	printf("\n\n -- 범죄 이력 -- \n\n");
	printf("이름 : %s\n", name);
	printf("나이 : %d\n", age);
	printf("몸무게 : %.2lf\n", weight);
	printf("키 : %.2lf\n", height);		
	printf("범죄명 : %s\n", content);		
							
	return 0;
}
