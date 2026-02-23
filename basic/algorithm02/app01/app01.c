// app01 - 검색 알고리즘
// 선형 검색

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// 매개변수가 const int인 이유 -> 함수 내에서 원본 배열을 변경하면 안되기 때문에
int search(const int[],int, int);	// const는 상수. 값 변경 불가

int main(void) {
	int nx, ky;
	puts(" 선형 검색 !");
	printf("요소 개수 > "); scanf("%d", &nx);	// 총 배열크기 입력
	int* x = calloc(nx, sizeof(int));
	
	for (int i = 0; i < nx; i++) {
		printf("x[%d]> ", i); scanf("%d", &x[i]);
	}
	// 검색 시작 
	printf("검색 값 > "); scanf("%d", &ky);
	int idx = search(x, nx, ky);	// 배열 x에 값이 ky인 요소를 선형검색
	if (idx == -1) {
		puts("찾는 값이 없습니다.");
		return 1;
	}
	else {
		printf("%d은(는) x[%d]에 있습니다.\n", ky, idx);
	}

	free(x);

	return 0;
}
// a[] 검색할 요소가 들어간 배열
// n 배열의 크기 
// key 배열에서 찾을 값
int search(const int a[],int n, int key) {
	int i = 0;
	while (1) {	// for문으로 변경해도 동일
		if (i == n) {
			return -1; // 검색 실패
				// 0, false
				// 1 이상, true
				// -1 이하, error 
		}
		if (a[i] == key) {
			return 1;
		}
		i++;
	}
}