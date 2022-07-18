#include <stdio.h>
#include <time.h>

int main(void) {

	// if문
	/*
	int age = 15;

	if (age >= 20) {
		printf("일반인 입니다\n");
	}
	else {
		printf("학생입니다\n");
	}
	*/

	// if / else if / else
	/*
	int age = 8;
	if (age >= 8 && age <= 13) {
		printf("초등학생입니다\n");
	}
	else if (age >= 14 && age <= 16) {
		printf("중학생입니다\n");
	}
	else if (age >= 17 && age <= 19) {
		printf("고등학생입니다\n");
	}
	else {
		printf("성인입니다\n");
	}
	*/

	// break / continue 문
	/*
	for (int i = 1; i <= 30; i++) {
		if (i >= 6) {
			printf("나머지 학생은 집에 가세요\n");
			break;
		}

		printf("%d번 학생은 조별 발표 준비를 하세요\n", i);
	}

	printf("\n\n");

	for (int i = 1; i <= 30; i++) {
		if (i >= 6 && i <= 10) {
			printf("%d번 학생은 조별 발표 준비를 하세요\n", i);

			if (i == 7) {
				printf("6번 학생은 조퇴네??\n");
				continue;
			}
		}
	}
	*/

	// &&(and) / ||(or) 추가
	/*
	int a = 10;
	int b = 10;
	int c = 12;
	int d = 13;

	if (a == b && c == d) {
		printf("a는 b와 같고, c는 d와 같습니다.\n");
	}
	else {
		printf("값이 다르네요\n");
	}

	if (a == b || c == d) {
		printf("a는 b와 같거나, c는 d와 같습니다.\n");
	}
	else {
		printf("값이 다르네요\n");
	}
	*/

	// swich문
	/*
	srand(time(NULL));

	// 가위 0, 바위 1, 보 2
	int i = rand() % 3; // 0~2반환(3으로 나눈 나머지)

	// break가 없으면 그 case의 아래 경우를 모두 출력한다(break 제거하고 실행시켜보자)
	switch(i) {
	case 0: printf("가위\n"); break;
	case 1: printf("바위\n"); break;
	case 2: printf("보\n"); break;
	default: printf("몰라요\n"); break;
	}

	// 조건문 스위치로 바꿔보기
	int age = 15;
	switch (age) {
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13: printf("초등학생입니다\n"); break;
	case 14:
	case 15:
	case 16: printf("중학생입니다\n"); break;
	case 17:
	case 18:
	case 19:printf("고등학생입니다\n"); break;
	default: printf("학생이 아닌가봐요??\n"); break;
	}
	*/

	// 프로젝트 : Up and Down

	srand(time(NULL));
	int num = rand() % 100 + 1; // 1~100 사이의 숫자
	printf("%d\n", num);

	int answer = 0;
	int chance = 5;

	while (chance >= 0) { // or while(1){ 도 가능 1은 참, 0은 거짓이다.따라서 chance가 0일때 break될때 까지 계속 돌라는 뜻
		printf("남은기회 %d 번 \n", chance--);
		printf("숫자를 맞춰보세요 (1~100) \n");
		scanf_s("%d", &answer);

		if (chance == 0) {
			printf("모든 기회를 사용했습니다 \n");
			break;
		}

		if (answer > num) {
			printf("Down \n");
		}
		else if (answer < num) {
			printf("Up \n");
		}
		else {
			printf("정답입니다 !\n\n");
			break;
		}
	}

	return 0;
}