#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
비밀번호를 입력받음
비밀번호가 일치하면 일기를 읽어와서 보여주고 수정할 수 있도록 함.
비밀번호가 일치하지않으면 메시지를 표시하고 종료합니다.
*/

#define MAX 10000
int main(void) {
    
    /*
    원래 getch 함수를 이용해서 비밀번호를 받았음.
    하지만 getch 함수는 비표준이라 리눅스 환경에서는 지원하지않음
    그래서 로직을 변경함...
    비밀번호 받는 부분은 추가적으로 변경이 필요함...
    */

    char line[MAX];
    char contents[MAX];
    char password[MAX];
    // char checkPW;

    printf("'비밀일기'에 오신것을 환영합니다.\n");
    printf("비밀번호를 입력하세요...\n");
    // int i = 0;
    
    scanf("%s", password);
    // printf("password : %s", password);

    /*
    while (1) {
	
	checkPW = getch();

	if (checkPW == 13) {
	    password[i] = '\0';
	    break;
	} else {
	    printf("*");
	    password[i] = checkPW;
	}
	i++;
    }
    */

    printf("\n\n --- 비밀번호 확인 중... --- \n\n");

    if (strcmp(password, "skehzheld") == 0) {
	printf("\n\n --- 비밀번호 확인 완료!! --- \n\n");
	char * fileName = "/home/choi/C/file/diary.txt";
	FILE * file = fopen(fileName, "a+b");
	// 파일이 없으면 생성, 있으면 append한다.

	if (file == NULL) {
	    printf("file open fail\n");
	    return 1;
	}

	while (fgets(line, MAX, file) != NULL) {
	    printf("%s", line);
	}

	printf("\n\n --- 내용을 계속 작성하세요. 종료하려면 'EXIT'를 입력하세요. --- \n\n");

	while (1) {
	    scanf("%[^\n]", contents); // \n이 나오기 전까지 모든 문자열을 읽어 처리함.
	    getchar(); // 엔터 입력 Flush 처리

	    if (strcmp(contents, "EXIT") == 0) {	
		printf("\n\n --- 비밀일기를 종료합니다. --- \n\n");
		break;
	    }

	    fputs(contents, file);
	    fputs("\n", file);
	}

	fclose(file);
    } else {
	printf("\n\n --- 비밀번호가 틀렸습니다. 사용 하실 수 없습니다. --- \n\n");
    }

    return 0;
}
