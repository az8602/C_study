#include <stdio.h>
#include <time.h>

int arrayAnimal[4][5];
int checkAnimal[4][5];
char* strAnimal[10]; // char pointer

void initAnimalArray();
void initAnimalName();
void suffleAnimal();
void printAnimals();
void printQuestion();

int getEmptyPosition();
int conv_pos_x();
int conv_pos_y();

int main(void) {

	// 다차원 배열
	/*
	int i = 1 ;
					//  ㅁ

	int arr[5] = {1, 2, 3, 4, 5};
					// ㅁㅁㅁㅁㅁ - 1차원 배열
	
	int arr2[2][5] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10}
	};
					// ㅁㅁㅁㅁㅁ - 2차원 배열    [0][0]  [0][1]  [0][2]  [0][3]  [0][4]
					// ㅁㅁㅁㅁㅁ				  [1][0]  [1][1]  [1][2]  [1][3]  [1][4]

	int arr3[4][2] = {
		{1,2},
		{3,4},
		{5,6},
		{7,8},
	};
					// ㅁㅁ
					// ㅁㅁ
					// ㅁㅁ
					// ㅁㅁ

	int arr4[3][3][3] = {
		{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
		{{10, 11, 12}, {13, 14, 15}, {16, 17, 18}},
		{{19, 20, 21}, {22, 23, 24}, {25, 26, 27}}
	};
					// ㅁㅁㅁ - 3차원 배열 [0][0][0]  [0][0][1]  [0][0][2]
					// ㅁㅁㅁ			   [0][1][0]  [0][1][1]  [0][2][2]
					// ㅁㅁㅁ			   [0][2][0]  [0][2][1]  [0][2][2]

					// ㅁㅁㅁ			   [1][0][0]  [1][0][1]  [1][0][2]
					// ㅁㅁㅁ			   [1][1][0]  [1][1][1]  [1][1][2]
					// ㅁㅁㅁ			   [1][2][0]  [1][2][1]  [1][2][2]

					// ㅁㅁㅁ			   [2][0][0]  [2][0][1]  [2][0][2]
					// ㅁㅁㅁ			   [2][1][0]  [2][1][1]  [2][1][2]
					// ㅁㅁㅁ			   [2][2][0]  [2][2][1]  [2][2][2]

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			printf("2차원 배열 (%d, %d)의 값  : %d\n", i, j, arr3[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				printf("3차원 배열 (%d, %d, %d)의 값  : %d\n", i, j, k,  arr4[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	*/

	// 프로젝트
	/*
	10마리의 서로 다른 동물 (각 카드 2장씩)
	사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
	모든 동물 쌍을 찾으면 게임 종료
	총 실패 횟수 알려주기
	*/

	srand(time(NULL));

	initAnimalArray();
	initAnimalName();
	
	suffleAnimal();

	int failCount = 0; // 실패 횟수

	while (1) {
		int select1 = 0; // 첫번째 선택수
		int select2 = 0; // 두번째 선택수

		printAnimals(); // 동물 위치 출력
		printQuestion(); // 문제 출력
		printf("뒤집을 카드를 2개 고르세요 : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2) {
			continue; // 무효 처리
		}

		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		if (checkAnimal[firstSelect_x][firstSelect_y] == 0 &&
			checkAnimal[secondSelect_x][secondSelect_y] == 0 &&
			(arrayAnimal[firstSelect_x][firstSelect_y] ==
				arrayAnimal[secondSelect_x][secondSelect_y])) { // 카드가 뒤집히지 않았는지 & 두 동물이 같은 동물일 경우
			printf("\n\n 빙고! : %s 발견 \n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		else { // 다른 동물일 경우
			printf("\n\n 땡! :(틀렸거나, 이미 뒤집힌 카드입니다!)\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;
		}

		if (foundAllAnimals() == 1) { // 모든 동물을 찾았는지 여부, 1 : 참, 0 : 거짓
			printf("\n\n 축하합니다! 모든 동물을 다 찾았네요 \n");
			printf("지금까지 총 %d번 실수하셨습니다.\n", failCount);
			break;
		}
	}
	return 0;
}

void initAnimalArray() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			arrayAnimal[i][j] = -1;
		}
	}
}

void initAnimalName() {
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

void suffleAnimal() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;
		}
	}
}

int getEmptyPosition() {
	while (1) {
		int randPos = rand() % 20; // 0 ~ 19 -> 좌표로 바꿔야 함
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1) {
			return randPos;
		}
	}
}

int conv_pos_x(int x) {
	return x / 5;
}

int conv_pos_y(int y) {
	return y % 5;
}

void printAnimals() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n=================================================\n\n");
}

void printQuestion() {
	printf("\n\n(문제)\n\n");
	int seq = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (checkAnimal[i][j] != 0) {
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			else {
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}

int foundAllAnimals() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (checkAnimal[i][j] == 0) {
				return 0;
			}
		}
	}
	return 1;
}