// pointer0 - 배열과 포인터 관계

#include <stdio.h>

int main(void) {
	int ary[] = { 10,30,50,70,90 };
	int* pa = ary;	// 배열변수의 요소[]를 빼면 배열변수의 시작주소를 뜻함
	int count = sizeof(ary) / sizeof(ary[0]);	// 20byte / 4byte =>5(배열 크기)

	for (int i = 0; i < count; i++) {
		printf("ary[%d]=%d\n", i, *(pa + i));	// == pa[i]
	}



	return 0;
}

// 배열 이름 = 첫 번째 요소 주소
// pa+1 은 자료형 크기만큼 1이동. 1바이트를 뜻하는게 아님
// ary[i]== *(ary+i)