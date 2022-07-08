#include <stdio.h>

// 한 프로젝트에서는 main함수는 하나만 존재해야 한다
int main(void) {

	// ++ 연산
	/*
	int a = 10;
	printf("a is %d\n", a);
	a++;
	printf("a is %d\n", a);

	int b = 20;
	printf("b is %d\n", ++b); // b = b+1;
	printf("b is %d\n", b++); // b를 사용한 이후 다음 문장으로 넘어갈때 1을 더해주라
	printf("b is %d\n", b);
	*/

	/*
	// 반복문(for)
	for (int i = 1; i <= 10; i++) {
		printf("Hello World(for) %d\n", i);
	}
	// 반복문(while)
	int i = 1;
	while (i <= 10) {
		// printf("Hello World(while) %d\n", i);
		// i++;
		// or
		printf("Hello World(while) %d\n", i++);
	}

	// 반복문(do while)
	int j = 1;
	do {
		printf("Hello World(do while) %d\n", j++);
	} while (j <= 10);

	// 이중 반복문
	for (int i = 2; i <= 9; i++) {
		printf("=====%d단=====\n", i);
		for (int j = 1; j <= 9; j++) {
			printf("%d X %d = %d\n", i, j, i*j);
		}
	}
	*/

	//별 찍기
	/*
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	*/

	//별 찍기(거꾸로))
	/*
	for (int i = 0; i < 5; i++) {
		for (int j = i; j <= 4; j++) {
			printf(" ");
		}
		for (int k = 0; k <= i; k++) {
			printf("*");
		}
		printf("\n");
	}
	*/

	/*
	피라미드를 쌓아라 프로젝트
	*/

	int floor;
	printf("몇 층으로 쌓겠느냐?");
	scanf_s("%d", &floor);

	for (int i = 0; i < floor; i++) {
		for (int j = i; j < floor - 1; j++) {
			printf(" ");
		}
		for (int k = 0; k < i * 2 + 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}