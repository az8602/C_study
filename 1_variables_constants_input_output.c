#include <stdio.h>
int main(void) {

	// 정수형 변주에 대한 예제
	/*
	int age = 12; // 변수 타입 변수명 = 값 ;(세미콜론)
	printf("%d\n", age);

	age = 13;
	printf("%d\n", age);
	*/

	// 실수형 변수에 대한 예제
	/*
	float f = 46.5f; // float를 쓸때는 무조건 f 사용
	printf("%f\n", f);
	printf("%.2f\n", f); // 소수점 둘째자리 까지만

	double d = 46.58;
	printf("%lf\n", d); // double은 lf로 사용
	printf("%.2lf\n", d);
	*/

	// 상수 예제
	/*
	const int YEAR = 2000;
	printf("태어난 년도 : %d\n", YEAR);
	// YEAR = 2001; 바꿀수 없다
	*/

	// printf 예제
	/*
	int add = 3 + 7; //10
	printf("3 + 7 = %d\n", add);
	printf("%d + %d = %d\n", 3, 7, 3 + 7);
	*/

	// scanf 예제
	/*
	int input;
	printf("값을 입력하세요 : ");
	scanf_s("%d", &input);
	printf("%d\n", input);

	int one, two, three;
	printf("3개의 정수를 입력하세요 : ");
	scanf_s("%d %d %d", &one, &two, &three);
	printf("첫번째 값 : %d\n", one);
	printf("두번째 값 : %d\n", two);
	printf("세번째 값 : %d\n", three);

	// 문자(한 글자), 문자열(한 글자 이상의 여러 글자)
	char c = 'A'; // 문자
	printf("%c\n", c);

	char str[256];
	scanf_s("%s", str, sizeof(str));
	printf("%s\n", str);
	*/

	// 프로젝트
	/*
	경찰관이 범죄자의 정보를 입수(조서 작성)
	이름? 나이? 몸무게? 키? 범죄명?
	*/

	char name[256];
	printf("이름이 뭐에요?");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("몇살이에요?");
	scanf_s("%d", &age);

	float weight;
	printf("몸무게가 몇이에요?");
	scanf_s("%f", &weight);

	double height;
	printf("키가 몇이에요?");
	scanf_s("%lf", &height);

	char what[256];
	printf("무슨 범죄를 저질렀어요?");
	scanf_s("%s", what, sizeof(what));

	// 조서 내용 출력
	printf("\n\n ---범죄자 정보--- \n\n");
	printf("이름 : %s\n", name);
	printf("나이 : %d\n", age);
	printf("몸무게 : %.2f\n", weight);
	printf("키 : %.2lf\n", height);
	printf("범죄 : %s\n", what);

	return 0;
}