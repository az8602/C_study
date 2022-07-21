#include <stdio.h>
#include <time.h>
// 구조체 정의(겹치는 부분이 있기 때문에)
struct GameInfo {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // 연관 업체 게임
};

// structure에 typedef를 정의하는 방법2
typedef struct GameInformation {
// typedef struct { 도 사용가능 --> 이름은 없지만 아래와 같은 내용을 GAME_INFO로 사용하겠다
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // 연관 업체 게임
} GAME_INFO;

typedef struct {
	char* name;
	int age;
	char* character;
	int level;
} CAT;

int collection[5] = { 0, 0, 0, 0, 0 };

CAT cats[5];

void initCats();
void printCat();
int checkCollection();

int main(void) {

	// 구조체
	/*
	// 이름 : 나도게임, 발매년도 : 2017, 가격 : 50원, 제작자 : 나도회사
	char* name = "나도게임";
	int year = 2017;
	int price = 50;
	char* company = "나도회사";

	// 이름 : 너도게임, 발매년도 : 2017, 가격 : 50원, 제작자 : 너도회사
	char* name2 = "너도게임";
	int year2 = 2017;
	int price2 = 100;
	char* company2 = "너도회사";
	// -> 비효율적이다

	// 구조체로 정의
	struct GameInfo gameInfo1;
	gameInfo1.name = "나도게임";
	gameInfo1.year = 2017;
	gameInfo1.price = 50;
	gameInfo1.company = "나도회사";

	// 구조체 출력
	printf("==== 게임 출시 정보 ==== \n");
	printf("          게임명        : %s\n", gameInfo1.name);
	printf("         발매년도       : %d\n", gameInfo1.year);
	printf("           가격         : %d\n", gameInfo1.price);
	printf("          제작사        : %s\n", gameInfo1.company);

	// 구조체를 배열처럼 초기화
	struct GameInfo gameInfo2 = { "너도게임", 2017, 100, "너도회사" };

	printf("==== 게임 출시 정보 ==== \n");
	printf("          게임명        : %s\n", gameInfo2.name);
	printf("         발매년도       : %d\n", gameInfo2.year);
	printf("           가격         : %d\n", gameInfo2.price);
	printf("          제작사        : %s\n", gameInfo2.company);

	// 구조체 배열
	struct GameInfo gameArray[2] = {
		{ "나도게임", 2017, 50, "나도회사" },
		{ "너도게임", 2017, 100, "너도회사" } };

	// 구조체 포인터
	struct GameInfo* gamePtr;
	gamePtr = &gameInfo1;

	printf("\n\n==== 미션맨의 게임 출시 정보 ==== \n");
	printf("           게임명         : %s\n", (*gamePtr).name);
	printf("          발매년도        : %d\n", (*gamePtr).year);
	printf("            가격          : %d\n", (*gamePtr).price);
	printf("           제작사         : %s\n", (*gamePtr).company);

	// 위의 프린트문과 동일한 역할
	printf("\n\n==== 미션맨의 게임 출시 정보 ==== \n");
	printf("           게임명         : %s\n", gamePtr -> name);
	printf("          발매년도        : %d\n", gamePtr -> year);
	printf("            가격          : %d\n", gamePtr -> price);
	printf("           제작사         : %s\n", gamePtr -> company);

	// 구조체 안에 구조체
	gameInfo1.friendGame = &gameInfo2;

	printf("\n\n==== 연관 업체의 게임 출시 정보 ==== \n");
	printf("           게임명         : %s\n", gameInfo1.friendGame -> name);
	printf("          발매년도        : %d\n", gameInfo1.friendGame -> year);
	printf("            가격          : %d\n", gameInfo1.friendGame -> price);
	printf("           제작사         : %s\n", gameInfo1.friendGame -> company);

	// typedef
	// 자료형에 이름(별명)을 지정
	int i = 1;
	typedef int 정수; // 지금부터 int == 정수
	typedef float 실수;

	정수 j = 3; // int j = 3;
	실수 k = 3.23f; // float f = 3.23;
	printf("정수 변수 : %d, 실수 변수 : %.2f\n\n", j, k);

	// structure에 typedef를 정의하는 방법1
	typedef struct GameInfo 게임정보;

	게임정보 game1;
	game1.name = "한글 게임";
	game1.year = 2015;

	GAME_INFO game2;
	game2.name = "한글 게임2";
	game2.year = 2014;

	// 사용은 가능하지만 위에서 typedef struct { 같이 정의할 경우 사용할 수 없다
	// struct GameInformation game3;
	// game3.name = "한글 게임";
	*/

	// 프로젝트
	/*
	5마리의 고양이가 있다
	아무키나 눌러서 랜덤으로 고양이를 뽑되
	5마리 모두 다 수집해서 열심히 키우면 됩니다!
	중복 발생 가능!
	*/

	// 고양이
	// 이름, 나이, 성격, 난이도
	srand(time(NULL));

	initCats();
	while (1) {
		printf("\n두근 두근! 어느 고양이의 집사가 될까요?\n 아무키나 눌러서 확인해보세요!");

		getchar(); // 어떤 키가 들어올 때 까지 대기

		int selected = rand() % 5;
		printCat(selected);
		collection[selected] = 1;

		int collectAll = checkCollection();
		if (collectAll == 1) {
			break;
		}
	}
	return 0;
}

void initCats() {
	cats[0].name = "깜냥이";
	cats[0].age = 5;
	cats[0].character = "온순";
	cats[0].level = 1;

	cats[1].name = "귀요미";
	cats[1].age = 3;
	cats[1].character = "날카로움";
	cats[1].level = 2;

	cats[2].name = "수줍이";
	cats[2].age = 7;
	cats[2].character = "잘 잠";
	cats[2].level = 3;

	cats[3].name = "까꿍이";
	cats[3].age = 2;
	cats[3].character = "시끄러움";
	cats[3].level = 4;

	cats[4].name = "돼냥이";
	cats[4].age = 1;
	cats[4].character = "배고픔";
	cats[4].level = 5;

}

void printCat(int selected) {
	printf("\n\n==== 당신은 이 고양이의 집사가 되었어요! ====\n\n");
	printf("이름                                       : %s\n", cats[selected].name);
	printf("나이                                       : %d\n", cats[selected].age);
	printf("특징                                       : %s\n", cats[selected].character);
	printf("레벨                                       : ");
	for (int i = 0; i < cats[selected].level; i++) {
		printf("%s", "★");
	}
}

int checkCollection() {

	int collectAll = 1;

	printf("\n\n === 보유한 고양이 목록이에요 === \n\n");
	for (int i = 0; i < 5; i++) {
		if (collection[i] == 0) {
			printf("%10s", "(빈 박스)");
			collectAll = 0;
		}
		else {
			printf("%10s", cats[i].name);
		}
	}
	printf("\n======================================\n\n");

	if (collectAll) {
		printf("\n\n 축하합니다! 모든 고양이를 다 모았어요, 열심히 키워주에쇼\n\n");
	}

	return collectAll;
}