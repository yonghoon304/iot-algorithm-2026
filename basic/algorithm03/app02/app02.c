// app02 - 팩토리얼 재귀방식
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

unsigned long long factorial(int n);

int main(void) {
	int x;
	unsigned long long result = 0;
	puts("재귀 호출");


	while (1) {
		printf("정수 입력 > "); scanf("%d", &x);
		if (x <= 0) break;

		result = factorial(x);

		printf("%d! = %llu", x, result);
	}
	return 0;
}

unsigned long long factorial(int n) {
	if (n > 0) {	// n * (n-1)!
		return (unsigned long long)n * factorial(n - 1);
	}
	else {	// 0!
		return 1;	// 반드시 종료조건이 있어야 함


	}
}