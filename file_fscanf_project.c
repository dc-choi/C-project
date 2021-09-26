#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
로또 추첨 번호 출력
난수로 생성받은 로또 번호를 저장한 파일을 불어온다.
파일의 값을 출력한다.
*/

#define MAX 10000
int main(void) {
    
    int inputNum[6] = {0, 0, 0, 0, 0, 0};
    int inputBouns = 0;

    char * fileName = "/home/choi/C/file/lotto.txt";
    FILE * file = fopen(fileName, "rb");

    if (file == NULL) {
	printf("file open fail");
	return 1;
    }
    
    printf("\n\n --- input lotto number (1 ~ 45) --- \n\n");
    printf("input number : ");
    fscanf(file, "%d %d %d %d %d %d\n", &inputNum[0], &inputNum[1], &inputNum[2], &inputNum[3], &inputNum[4], &inputNum[5]);
    printf("%d %d %d %d %d %d\n", inputNum[0], inputNum[1], inputNum[2], inputNum[3], inputNum[4], inputNum[5]);

    printf("\n\n --- input lotto bouns number (1 ~ 45) --- \n\n");
    printf("input number : ");
    fscanf(file, "%d\n", &inputBouns);
    printf("%d\n", inputBouns);

    fclose(file);

    return 0;
}
