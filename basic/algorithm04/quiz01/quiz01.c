// 1. 스택 1. 공백 없는 문자열 s가 있습니다. 스택을 사용하여 문자열을 뒤집어 출력하는 소스를 작성하세요. 힌트) 한 글자씩 스택에...
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int max;	// 스택 용량
	int ptr;	// 스택 포인터
	char* stk;	// 스택 첫 주소
}IntStack;


int Initialize(IntStack* st, int max);
int Push(IntStack* st, char x);
int Pop(IntStack* st, char* x);

int main(void) {
	IntStack st;

	char str[100];
	char ch;

	puts("문자열 뒤집기 알고리즘");
	printf("문자열 입력 : "); scanf("%s", str);
	int len = strlen(str);

	if (Initialize(&st, len) == -1) {
		puts("스택 초기화 실패");
		return -1;
	}

	for (int i = 0; i < len; i++) {
		Push(&st, str[i]);
	}
	
	printf("뒤집은 문자열 : ");
	while (st.ptr > 0) {
		Pop(&st, &ch);
		printf("%c", ch);
	}
	

	return 0;
}






// 스택 초기화
int Initialize(IntStack* st, int max) {
	st->ptr = 0;
	if ((st->stk = (char*)calloc(max, sizeof(char))) == NULL) {
		st->max = 0;
		return -1;
	}
	st->max = max;
	return 0;
}

// 스택 푸시
int Push(IntStack* st, char x) {
	if (st->ptr >= st->max) {
		return -1;
	}
	st->stk[st->ptr] = x;
	st->ptr++;

	return 0;
}

// 스택 팝
int Pop(IntStack* st, char* x) {
	if (st->ptr <= 0) {
		return -1;
	}
	st->ptr--;
	*x = st->stk[st->ptr];

	return 0;
}
