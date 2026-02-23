#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 100

// 영화 구조체 정의
typedef struct {
    char title[NAME_LEN];
    int year;
    float rating;
} Movie;

// 동적 배열 구조체 정의
typedef struct {
    Movie* data;
    int size;     // 현재 영화 개수
    int capacity; // 배열 용량
} MovieList;

// 초기화 함수
void initMovieList(MovieList* list) {
    list->size = 0;
    list->capacity = 2; // 초기 용량
    list->data = (Movie*)malloc(sizeof(Movie) * list->capacity);
    if (list->data == NULL) {
        printf("메모리 할당 실패!\n");
        exit(1);
    }
}

// 배열 확장 함수
void resizeMovieList(MovieList* list) {
    list->capacity *= 2;
    Movie* temp = (Movie*)realloc(list->data, sizeof(Movie) * list->capacity);
    if (temp == NULL) {
        printf("메모리 재할당 실패!\n");
        free(list->data);
        exit(1);
    }
    list->data = temp;
}

// 영화 추가 함수
void addMovie(MovieList* list) {
    if (list->size == list->capacity) {
        resizeMovieList(list);
    }

    Movie m;
    printf("영화 제목: ");
    getchar(); // 개행 제거
    fgets(m.title, NAME_LEN, stdin);
    m.title[strcspn(m.title, "\n")] = '\0'; // 개행 제거

    printf("개봉 연도: ");
    scanf("%d", &m.year);

    printf("평점(0~10): ");
    scanf("%f", &m.rating);

    list->data[list->size++] = m;
    printf("영화가 추가되었습니다!\n");
}

// 영화 목록 출력 함수
void listMovies(MovieList* list) {
    if (list->size == 0) {
        printf("등록된 영화가 없습니다.\n");
        return;
    }

    printf("\n=== 영화 목록 ===\n");
    for (int i = 0; i < list->size; i++) {
        printf("%d. %s (%d) - 평점: %.1f\n", i + 1,
            list->data[i].title, list->data[i].year, list->data[i].rating);
    }
}

// 영화 삭제 함수
void deleteMovie(MovieList* list) {
    if (list->size == 0) {
        printf("삭제할 영화가 없습니다.\n");
        return;
    }

    listMovies(list);
    printf("삭제할 영화 번호: ");
    int idx;
    scanf("%d", &idx);

    if (idx < 1 || idx > list->size) {
        printf("잘못된 번호입니다.\n");
        return;
    }

    for (int i = idx - 1; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
    printf("영화가 삭제되었습니다!\n");
}

// 메모리 해제
void freeMovieList(MovieList* list) {
    free(list->data);
}

int main() {
    MovieList list;
    initMovieList(&list);

    int choice;
    while (1) {
        printf("\n=== 영화 관리 프로그램 ===\n");
        printf("1. 영화 추가\n");
        printf("2. 영화 목록\n");
        printf("3. 영화 삭제\n");
        printf("4. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addMovie(&list);
            break;
        case 2:
            listMovies(&list);
            break;
        case 3:
            deleteMovie(&list);
            break;
        case 4:
            freeMovieList(&list);
            printf("프로그램 종료\n");
            return 0;
        default:
            printf("잘못된 선택입니다.\n");
        }
    }
}