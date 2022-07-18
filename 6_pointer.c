#include <stdio.h>
#include <time.h>

void swap(int a, int b);
void swap_addr(int* a, int* b);
void changeArray(int* ptr);

int level;
int arrayFish[6];
int* cursor;
void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

int main(void) {
	
	// 포인터 기초
	/*
	// [철수] : 101호 --> 메모리 공간의 주소
	// [영희] : 201호
	// [민수] : 301호
	
	// 각 문 앞에 '암호'가 있음
	
	int 철수 = 1; // 암호
	int 영희 = 2;
	int 민수 = 3;

	printf("철수네 주소 : %d, 암호 : %d\n", &철수, 철수);
	printf("영희네 주소 : %d, 암호 : %d\n", &영희, 영희);
	printf("민수네 주소 : %d, 암호 : %d\n", &민수, 민수);

	// 미션맨
	// 첫번째 미션 : 아파트의 각 집에 방문하여 문에 적힌 암호 확인
	// 두번째 미션 : 각 암호에 3을 곱해라

	int* 미션맨; // 포인터 변수

	// 첫번째 미션
	printf("\n... 첫번째 미션 수행중...\n");
	미션맨 = &철수;
	printf("미션맨이 방문하는 곳 주소 %d, 암호 : %d\n", 미션맨, *미션맨);

	미션맨 = &영희;
	printf("미션맨이 방문하는 곳 주소 %d, 암호 : %d\n", 미션맨, *미션맨);

	미션맨 = &민수;
	printf("미션맨이 방문하는 곳 주소 %d, 암호 : %d\n", 미션맨, *미션맨);

	// 두번째 미션
	printf("\n... 두번째 미션 수행중...\n");
	미션맨 = &철수;
	*미션맨 = *미션맨 * 3;
	printf("미션맨이 방문하는 곳 주소 %d, 암호 : %d\n", 미션맨, *미션맨);

	미션맨 = &영희;
	*미션맨 = *미션맨 * 3;
	printf("미션맨이 방문하는 곳 주소 %d, 암호 : %d\n", 미션맨, *미션맨);

	미션맨 = &민수;
	*미션맨 = *미션맨 * 3;
	printf("미션맨이 방문하는 곳 주소 %d, 암호 : %d\n", 미션맨, *미션맨);


	// 스파이
	// 미션맨이 바꾼 암호에서 2를 빼라

	int* 스파이 = 미션맨;
	printf("\n.... 스파이가 미션 수행하는 중...\n");
	스파이 = &철수;
	*스파이 = *스파이 - 2; // 철수 = 철수 - 2;
	printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);

	스파이 = &영희;
	*스파이 = *스파이 - 2;
	printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);

	스파이 = &민수;
	*스파이 = *스파이 - 2;
	printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);

	printf("\n... 철수 영희 민수는 집에 오고서는 놀랐습니다...\n");
	printf("철수네 주소 : %d, 암호 : %d\n", &철수, 철수);
	printf("영희네 주소 : %d, 암호 : %d\n", &영희, 영희);
	printf("민수네 주소 : %d, 암호 : %d\n", &민수, 민수);

	printf("미션맨의 주소 %d\n", &미션맨);
	printf("스파이의 주소 %d\n", &스파이);
	*/

	// 배열과 포인터
	/*
	int arr[3] = { 5, 10, 15 };
	int* ptr = arr;
	for (int i = 0; i < 3; i++) {
		printf("배열 arr[%d]의 값 %d\n", i, arr[i]);
	}

	for (int i = 0; i < 3; i++) {
		printf("포인터 ptr[%d]의 값 %d\n", i, ptr[i]);
	}

	ptr[0] = 100;
	ptr[1] = 200;
	ptr[2] = 300;

	for (int i = 0; i < 3; i++) {
		// printf("배열 arr[%d]의 값 %d\n", i, arr[i]);
		printf("배열 arr[%d]의 값 %d\n", i, *(arr + i));
	}

	for (int i = 0; i < 3; i++) {
		printf("포인터 ptr[%d]의 값 %d\n", i, *(ptr + i));
	}

	// *(arr + i) = arr[i]
	// arr == arr배열의 첫번째 값의 주소와 동일 == &arr[0]
	printf("arr자체의 값 : %d\n", arr);
	printf("arr[0]의 주소 : %d\n", &arr[0]);

	printf("arr자체의 값이 가지는 주소의 실제값 : %d\n", *arr); // == *(arr + 0)
	printf("arr[0]의 실제 값 : %d\n", *&arr[0]);

	// *& : 아무것도 없는 것과 같다 &(주소), *(주소의 값) --> 상쇄가 된다
	printf("arr[0]의 실제 값 : %d\n", *&*&*&*&*&*&*&*&*&*&arr[0]);
	printf("arr[0]의 실제 값 : %d\n", arr[0]);
	*/
	
	// Swap(a와 b의 값을 바꾼다)
	/*
	int a = 10;
	int b = 20;
	printf("a의 주소 : %d\n", &a);
	printf("b의 주소 : %d\n", &b);

	printf("Before Swap => a : %d, b : %d\n", a, b);
	swap(a, b);
	printf("After Swap => a : %d, b : %d\n", a, b);

	// 값에 의한 복사(Call by Value) -> 값만 복사한다는 의미
	
	// 주소값을 넘기면 다음과 같다
	printf("(주소값)Before Swap => a : %d, b : %d\n", a, b);
	swap_addr(&a, &b);
	printf("(주소값)After Swap => a : %d, b : %d\n", a, b);
	*/

	// 배열일때 주소변경
	/*
	int arr2[3] = { 10, 20, 30 };
	// changeArray(arr2);
	changeArray(&arr2[0]);

	for (int i = 0; i < 3; i++) {
		printf("%d\n", arr2[i]);
	}

	// scanf에서 &num과 같이 &를 사용하는 이유
	*/

	// 프로젝트
	/*
	물고기가 6마리가 있을 때 물이 줄어든다
	물이 다 증발하기 전에 물을 넣어서 물고기를 살려야 한다
	*/
	long startTime = 0; // 게임 시작 시간
	long totalElapsedTime = 0; // 총 경과 시간
	long prevElapsedTime = 0; // 직전 경과 시간 (최근에 물을 준 시간 간격)

	int num; // 몇번 어항에 물을 줄 것인지 (사용자 입력)

	initData();
	cursor = arrayFish; // cursor[0] .. cursor[1] ..

	startTime = clock(); // 현재 시간을 millisecond(1000분의 1초)로 반환
	while (1) { // 계속 반복
		printfFishes();
		// getchar(); // 입력 대기
		printf("몇번 어항에 물을 주시겠어요? :");
		scanf_s("%d", &num);

		// 입력값 체크
		if (num < 1 || num > 6) {
			printf("\n입력값이 잘못되었습니다\n");
			continue;
		}

		// 총 경과 시간
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // 초단위로 바꿔줌
		printf("총 경과 시간 : %ld 초\n", totalElapsedTime);

		// 직전 물 준 시간
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);

		// 어항의 물을 감소(증발)
		decreaseWater(prevElapsedTime);

		// 사용자가 입력한 어항에 물을 준다
			// 1. 어항의 물이 0이면 --> 물을 주지 않는다
		if (cursor[num - 1] <= 0) {
			printf("%d 번 물고기는 이미 죽었습니다. 물을 주지 않습니다\n", num);
		}
			// 2. 물이 0이 아닌 경우 --> 물을 준다, 100을 넘지 않는지 체크
		else if (cursor[num - 1] + 1 <= 100) {
			// 물을 준다
			printf("%d 번 어항에 물을 줍니다 \n\n", num);
			cursor[num - 1] += 1;
		}

		// 레벨업
		if (totalElapsedTime / 20 > level - 1) {
			level++;
			printf("*** 축 레벨업 ! 기존 %d레벨에서 %d레벨로 업그레이드 ***\n\n", level - 1, level);

			if (level == 5) {
				printf("\n\n축하합시나. 최고 레벨을 달성하였습니다. 게임을 종료합니다.\n\n");
				exit(0); // 모든 프로그램을 끝냄
			}
		}

		// 모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0) {
			printf("모든 물고기 가 죽었습니다\n");
			exit(0);
		}
		else {
			printf("물고기가 아직 살아있어요1\n");
		}
		prevElapsedTime = totalElapsedTime;

		// 10초 -> 15초 (5초 : prevElapsedTime -> 15초) -> 25초 (10초?) --> 5초를 이미 썼기 때문에 바꿔줌
	}
	return 0;
}

void swap(int a, int b) {

	printf("a의 주소(in swap) : %d\n", &a);
	printf("b의 주소(in swap) : %d\n", &b);

	int temp = a;
	a = b;
	b = temp;
	printf("After Swap(in swap function) => a : %d, b : %d\n", a, b);
}

void swap_addr(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("(주소값)After Swap(in swap function) => a : %d, b : %d\n", *a, *b);
}

void changeArray(int* ptr) {
	ptr[2] = 50;
}

// 프로젝트용 함수
void initData() {
	level = 1;
	for (int i = 0; i < 6; i++) {
	 arrayFish[i] = 100; // 어항의 물 높이(0~100)
	}
}

void printfFishes() {
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++) {
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime) {
	for (int i = 0; i < 6; i++) {
		arrayFish[i] -= (level * 3 * (int)elapsedTime); // 3을 난이도 조절을 위한 값
		
		if (arrayFish[i] < 0) {
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive() {
	for (int i = 0; i < 6; i++) {
		if (arrayFish[i] > 0) {
			return 1;
		}
	}
	return 0;
}