#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
로또 추첨 번호 저장
난수를 생성받아서 로또 번호를 생성한 후
그 값을 파일에 저장한다.
*/

#define MAX 10000
int main(void) {

    srand(time(NULL));
    
    int randNum[6] = {0, 0, 0, 0, 0, 0};
    int randBouns = 0;

    char * fileName = "/home/choi/C/file/lotto.txt";
    FILE * file = fopen(fileName, "wb");

    if (file == NULL) {
	printf("file open fail");
	return 1;
    }

    printf("\n\n --- get random number ... (1 ~ 45) --- \n\n");
    for (int i = 0; i < 6; i++) {
	randNum[i] = rand() % 45 + 1; // 1 ~ 45의 숫자 입력
    } 
    fprintf(file, "%d %d %d %d %d %d\n", randNum[0], randNum[1], randNum[2], randNum[3], randNum[4], randNum[5]);

    printf("\n\n --- get random bouns number ... (1 ~ 45) --- \n\n");
    randBouns = rand() % 45 + 1;
    fprintf(file, "%d\n", randBouns);

    fclose(file);

    return 0;
}
