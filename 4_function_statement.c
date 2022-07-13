#include <stdio.h>
#include <time.h>

// 선언
void p(int num);
void function_without_return();
int function_with_return_int();

void function_without_params();
void function_with_params_int(int num1, int num2, int num3);

int apple(int num1, int num2);

// 계산기용 함수 선언
int add(int num1, int num2);
int sub(int num1, int num2);
int mul(int num1, int num2);
int div(int num1, int num2);

// 프로젝트용 함수 선언
int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main(void) {

	// 함수
	/*
	int num = 2;
	p(num);

	// 2+3?
	num = num + 3; // num += 3;
	p(num);

	// 5-1?
	num -= 1; // num = num -1;
	p(num);

	// 4x3?
	num *= 3;
	p(num);

	// 12/6?
	num /= 6;
	p(num);
	*/

	/*
	함수의 구성
		반환형 함수이름(전달값)
		main함수 위에서 선언한 양식과 동일해야한다

	함수의 종류
		return 값이 없는 함수 : void
		return 값이 있는 함수 : int, float, char 등..
		
		전달값이 없는 함수 : input이 없음
		전달값이 있는 함수 : input이 있음
	*/
	
	/*
	function_without_return();

	int ret = function_with_return_int();
	p(ret);

	function_without_params();

	function_with_params_int(1, 2, 3);

	int ret2 = apple(5, 2); // 5개의 사과중에서 2개를 먹었습니다
	printf("사과 %d개에서 %d개를 먹은 이후 남은 개수는 %d입니다.", 5, 2, apple(5, 2)); // return값이 있을 때 이런 식으로 사용해도 됩니다(밑의 함수에서 printf를 주석처리 한 이후)
	*/

	/*
	int num = 2;
	num = add(num, 3);
	p(num);

	num - sub(num, 1);
	p(num);

	num = mul(num, 3);
	p(num);

	num = div(num, 6);
	p(num);
	*/

	/*
	프로젝트
	문이 5개가 있고, 각 문마다 점점 어려운 수식 퀴즈가 출제
	맞히면 통과, 틀리면 실패
	*/

	srand(time(NULL));
	int count = 0;
	for (int i = 1; i <= 5; i++) {

		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		showQuestion(i, num1, num2);

		int answer = -1;
		scanf_s("%d", &answer);

		if (answer == -1) {
			printf("프로그램을 종료합니다\n");
			exit(0); //프로그램을 끝내라는 의미, break를 할 경우 밑의 반복문 밖의 출력문이 실행되기 때문
		}
		else if (answer == num1 * num2) {
			success();
			count++;
		}
		else {
			fail();
		}
	}

	printf("\n\n당신은 5개의 비밀번호에서 %d개의 문제를 맞췄습니다.\n", count);

	return 0;
}

// 정의
void p(int num) {
	printf("num is %d\n", num);
}

void function_without_return() {
	printf("반환값이 없는 함수입니다.\n");
}

int function_with_return_int() {
	printf("반환값이 있는 함수입니다.\n");
	return 10;
}

void function_without_params() {
	printf("전달값이 없는 함수입니다.\n");
}

void function_with_params_int(int num1, int num2, int num3) {
	printf("전달값이 있는 함수입니다, 전달받은 값은 %d, %d, %d 입니다.\n", num1, num2, num3);
}

int apple(int num1, int num2) {
	// printf("사과 %d개에서 %d개를 먹었더니 %d개가 남았네요.\n", num1, num2, num1 - num2);
	return num1 - num2;
}

int add(int num1, int num2) {
	return num1 + num2;
}

int sub(int num1, int num2) {
	return num1 - num2;
}

int mul(int num1, int num2) {
	return num1 * num2;
}

int div(int num1, int num2) {
	return num1 / num2;
}

// 프로젝트용 함수 정의
int getRandomNumber(int level) {
	return rand() % (level * 7) + 1; // level * 7로 나눈 나머지이므로 0 ~ level * 7 -1 사이의 값이 나온다
}

void showQuestion(int level, int num1, int num2){
	printf("\n\n\n######### %d 번째 비밀번호 ########\n", level);
	printf("\n\t %d x %d = ?\n\n", num1, num2);
	printf("##################################\n");
	printf("\n비밀번호를 입력하세요(종료 = -1) >>");
}

void success() {
	printf("\n >> Good! \n");
}

void fail() {
		printf("\n >> Fail! \n");
}