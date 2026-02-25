// quiz03 3. 정수 N이 주어집니다. 재귀함수로 1+2+....+N 값을 출력하는 소스를 작성하세요. 예) 입력 5->출력 15
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int func(int n);

int main(void) {
	int x=0;
	printf(" 정수 N을 입력하시오 > "); scanf("%d", &x);
	printf(" 답은 : %d", func(x));

	return 0;
}

int func(int n) {
	if (n > 0) {
		return n + func(n - 1);
	}
	else {
		return 0;
	}
}