// quiz02 2. 1부터 N까지 적힌 카드가 있습니다. 다음 과정을 카드가 1장 남을 때까지 반복합니다. 마지막 카드번호를 출력하는 소스를 작성하세요. 
// -맨 위 카드 1장을 버린다
// - 그 다음 맨 위 카드 1장을 맨 아래로 옮긴다
// 예) 입력 6->결과 4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	printf("정수 N을 입력하시오 > "); scanf("%d", &n);
	int front = 0;
	int rear = n;

	int ary[100];

	// 카드 초기화
	for (int i = 0; i < n; i++) {
		ary[i] = i + 1;
	}
	// 반복
	while (rear-front>1) {
		front++;

		ary[rear] = ary[front];
		rear++;
		front++;
	}
	printf("결과 : %d ", ary[front]);


	return 0;
}