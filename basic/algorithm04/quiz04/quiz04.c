// quiz04 4. 학생의 이름과 점수가 N명 주어집니다. 최고 점수 학생의 이름과 점수를 출력하는 소스를 작성하세요. 
// 최고 점수가 동점일 경우 먼저 나온 점수가 결정됩니다. 예) 입력 4 김 70 이 88 박 88 최 60 출력 이 88
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main() {
    int N;
    char name[50];
    char topName[50];
    int score;
    int topScore = -1; // 안전빵
    puts("정수 N 입력");
    scanf("%d", &N);

    for (int i = 1; i < N+1; i++) {
        printf("[%d]번 이름과 점수 입력하세요 > ",i);
        scanf("%s %d", name, &score);

        if (score > topScore) {   // 동점은 제외 (먼저 나온 학생 유지)
            topScore = score;
            sprintf(topName, "%s", name);   // 메모이제이션
        }
    }

    printf("%s %d\n", topName, topScore);

    return 0;
}