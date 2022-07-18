#include <stdio.h>
#include <time.h>
int main(void) {

	// 배열 사용 X
	/*
	int subway_1 = 30;
	int subway_2 = 40;
	int subway_3 = 50;

	printf("지하철 1호차에 %d명이 타고 있습니다\n", subway_1);
	printf("지하철 2호차에 %d명이 타고 있습니다\n", subway_2);
	printf("지하철 3호차에 %d명이 타고 있습니다\n", subway_3);
	*/

	// 배열 사용
	/*
	int subway_array[3];
	subway_array[0] = 30;
	subway_array[1] = 40;
	subway_array[2] = 50;

	for (int i = 0; i < 3; i++) {
		printf("지하철 %d호차에 %d명이 타고 있습니다\n",i+1 , subway_array[i]);
	}

	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}

	// 더미값이 들어감, 초기화 해줘야 합니다
	int arr2[10];
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr2[i]);
	}

	// 하나라도 선언해주면 자동으로 0으로 초기화
	int arr3[10] = {1, 2};
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr3[i]);
	}

	// 다음과 같이 선언 가능
	int arr4[] = {1, 2}; // arr4[2]

	// float도 0.0으로 빈 공간 초기화
	float arr_f[5] = { 1.0f, 2.0f, 3.0f };
	for (int i = 0; i < 5; i++) {
		printf("%.2f\n", arr_f[i]);
	}
	*/

	// 배열 크기는 항상 상수로 선언
	/*
	int size = 10;
	int arr[size] 불가능
	*/

	// 문자 vs 문자열
	/*
	char c = 'A'; // 문자
	printf("%c\n", c);

	// 문자열 끝에는 '끝'을 의미하는 NULL문자가 필요함 \0
	// 없을 경우 이상한 문자가 생성됨
	// char str[6] = "coding"; //[c][o][d][i][n][g]
	char str[7] = "coding"; //[c][o][d][i][n][g] + [\0]
	printf("%s\n", str);

	char str2[] = "coding";
	printf("%s\n", str2);
	printf("%d\n", sizeof(str2));

	for (int i = 0; i < sizeof(str2);i++) {
		printf("%c\n", str[i]);
	}

	char kor[] = "나도코딩";
	printf("%s\n", kor);
	printf("%d\n", sizeof(kor));
	// 영어 한 글자 : 1byte
	// 한글 한 글자 : 2byte

	// char 크기 : 1byte, 따라서 한글은 사이즈가 *2 + 1
	*/

	// 아스키 코드
	/*
	// 앞에서의 문자열 정의와 동일
	char c_array[7] = { 'c', 'o','d','i','n','g','\0' };
	printf("%s\n", c_array);

	char c_array2[10] = { 'c', 'o','d','i','n','g','\0' };
	printf("%s\n", c_array2);

	for (int i = 0; i < sizeof(c_array2); i++) {
		printf("%c\n",c_array2[i]); // 8부터는 빈공간
	}

	for (int i = 0; i < sizeof(c_array2); i++) {
		printf("%d\n", c_array2[i]); // ASCII 코드 값이 나온다(d)
	}

	char name[256];
	printf("이름을 입력하세요 : ");
	scanf_s("%s", name, sizeof(name));
	printf("%s\n", name);

	// 참고 : ASCII : ANSI(미국표준협회)에서 제시한 표준 코드 체계
	// 7bit, 총 128개 코드 (0 ~ 127)
	// a : 97, A : 65, O : 48 등 정수값으로 표시

	printf("%c\n", 'a');
	printf("%d\n", 'a');
	printf("%c\n", 97);

	for (int i = 0; i < 128; i++) {
		printf("아스키 코드 정소 %d, : %c\n", i, i);
	}
	*/

	// 프로젝트 : 아빠는 대머리
	srand(time(NULL));
	printf("\nn === 아빠는 대머리 게임 === \n\n");
	int answer;
	int treatment = rand() % 4;
	
	int cntShowBottle = 0;
	int prevCntShowBottle = 0;

	for (int i = 1; i <= 3; i++) {

		int bottle[4] = { 0,0,0,0 };

		do {
			cntShowBottle = rand() % 2 + 2;
		} while (cntShowBottle == prevCntShowBottle);

		prevCntShowBottle = cntShowBottle;

		int isincluded = 0;
		printf("> %d 번째 시도 : ", i);

		for (int j = 0; j < cntShowBottle; j++) {
			int randBottle = rand() % 4;

			if (bottle[randBottle] == 0) {
				bottle[randBottle] = 1;

				if (randBottle == treatment) {
					isincluded = 1;
				}
			}
			else {
				j--;
			}
		}

		for (int k = 0; k < 4; k++) {
			if (bottle[k] == 1) {
				printf("%d ", k + 1);
			}
		}
		printf("물약을 머리에 바릅니다\n\n");

		if (isincluded == 1) {
			printf(">> 성공 !\n");
		}
		else {
			printf(">> 실패 !\n");
		}

		printf("\n... 계속 하려면 아무키나 누르세요...");
		getchar(); // 대기용
	}

	printf("\n\n 발모제는 몇 번 일까요? :");
	scanf_s("%d", &answer);

	if (answer - 1 == treatment) {
		printf("\n >> 정답입니다 !\n");
	}
	else {
		printf("\n >> 틀렸어요 ! 정답은 %d입니다.\n", treatment + 1);
	}


	return 0;
}

