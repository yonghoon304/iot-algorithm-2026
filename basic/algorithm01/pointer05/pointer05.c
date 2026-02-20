// pointer05 - 구조체와 포인터

#include <stdio.h>

typedef struct {
	char name[20];
	int age;
} person;

int main(void) {
	person p1 = { .name = "hoon",.age = 28 };
	person* ptr = &p1;

	printf("이름 : %s\n", ptr->name);	// == *(ptr).name
	printf("나이 : %d\n", ptr->age);

	return 0;
}

// 구조체와 포인터는 함께 사용되는 경우가 매우 많음
// 특히 임베디드/OS/Network 등에서 필수