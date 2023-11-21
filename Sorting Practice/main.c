#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int list[MAX_SIZE];
int n;

// 선택 정렬 함수
void selection_sort(int list[], int n, int* move_count, int* compare_count, int print) {
	int least, temp;

	for (int i = 0; i < n - 1; i++) {
		least = i;
		(*move_count)++;

		// print가 1일 경우에만 과정 출력
		if (print == 1) {
			for (int k = 0; k < n; k++) {
				printf("%d ", list[k]);
			}
			printf("\n");
		}

		for (int j = i+1; j < n; j++) {
			if (list[j] < list[least]) least = j;
			(*compare_count)++;
		}
		SWAP(list[i], list[least], temp);
	}
}

// 삽입 정렬 함수
void insertion_sort(int list[], int n, int* move_count, int* compare_count, int print) {
	int i,j,key;

	for (i = 1; i < n; i++) {
		key = list[i];
	
		// print가 1일 경우에만 정렬 과정 출력
		if (print == 1) {
			for (int k = 0; k < n; k++) {
				printf("%d ", list[k]);
			}
			printf("\n");
		}

		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			(*move_count)++;
			(*compare_count)++;
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
}

// 버블 정렬 함수
void bubble_sort(int list[], int n, int* move_count, int* compare_cout, int print) {
	int temp;

	for (int i = n - 1; i > 0; i--) {

		// print가 1일 경우에만 정렬 과정 출력
		if (print == 1) {
			for (int k = 0; k < n; k++) {
				printf("%d ", list[k]);
			}
			printf("\n");
		}

		for (int j = 0; j < i; j++) {
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
				(*move_count)++;
			}
			(*compare_cout)++;
		}
	}
}

int main()
{
	n = MAX_SIZE;
	// 이동 횟수, 비교 횟수 변수
	int move_count = 0;
	int compare_count = 0;
	// 이동 횟수 합, 비교 횟수 합
	int sum_move = 0;
	int sum_compare = 0;
	// 선택 정렬 이동, 비교 횟수 배열 및 평균값 저장 변수
	int move_sel[MAX_SIZE] = { 0 };
	int compare_sel[MAX_SIZE] = { 0 };
	double average_move_sel = 0;
	double average_compare_sel = 0;
	// 삽입 정렬 이동, 비교 횟수 배열 및 평균값 저장 변수
	int move_insert[MAX_SIZE] = { 0 };
	int compare_insert[MAX_SIZE] = { 0 };
	double average_move_insert = 0;
	double average_compare_insert = 0;
	// 버블 정렬 이동, 비교 횟수 배열 및 평균값 저장 변수
	int move_bubble[MAX_SIZE] = { 0 };
	int compare_bubble[MAX_SIZE] = { 0 };
	double average_move_bubble = 0;
	double average_compare_bubble = 0;

	// 난수 리스트 생성
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		list[i] = rand() % 100;
	}

	// 선택 정렬

	printf("Original List\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n\n");

	printf("Selection List\n");
	selection_sort(list, n, &move_count, &compare_count, 1);

	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
	printf("Move : %d\n", move_count);
	move_sel[0] = move_count;
	printf("Compare : %d\n", compare_count);
	compare_sel[0] = compare_count;

	// 삽입 정렬

	// 이동 및 비교 횟수 초기화
	move_count = 0;
	compare_count = 0;

	// 난수 리스트 생성
	for (int i = 0; i < n; i++) {
		list[i] = rand() % 100;
	}
	printf("\nOriginal List\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n\n");

	printf("Insertion List\n");
	insertion_sort(list, n, &move_count, &compare_count, 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
	printf("Move : %d\n", move_count);
	move_insert[0] = move_count;
	printf("Compare : %d\n", compare_count);
	compare_insert[0] = compare_count;

	// 버블 정렬

	// 이동 및 비교 횟수 초기화
	move_count = 0;
	compare_count = 0;

	// 난수 리스트 생성
	for (int i = 0; i < n; i++) {
		list[i] = rand() % 100;
	}
	printf("\nOriginal List\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n\n");

	printf("Bubble List\n");
	bubble_sort(list, n, &move_count, &compare_count, 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
	printf("Move : %d\n", move_count);
	move_bubble[0] = move_count;
	printf("Compare : %d\n", compare_count);
	compare_bubble[0] = compare_count;

	// 선택 정렬 반복 시행

	for (int i = 1; i < MAX_SIZE; i++) {
		move_count = 0;
		compare_count = 0;

		for (int i = 0; i < n; i++) {
			list[i] = rand() % 100;
		}

		selection_sort(list, n, &move_count, &compare_count, 0);

		move_sel[i] = move_count;
		compare_sel[i] = compare_count;
	}

	for (int i = 0; i < n; i++) {
		sum_move += move_sel[i];
		sum_compare += compare_sel[i];
	}

	average_move_sel = sum_move / 20;
	average_compare_sel = sum_compare / 20;

	// 삽입 정렬 반복 시행

	for (int i = 1; i < MAX_SIZE; i++) {
		move_count = 0;
		compare_count = 0;

		for (int i = 0; i < n; i++) {
			list[i] = rand() % 100;
		}

		insertion_sort(list, n, &move_count, &compare_count, 0);

		move_insert[i] = move_count;
		compare_insert[i] = compare_count;
	}

	// 이동횟수,비교횟수 합 변수 초기화
	sum_move = 0;
	sum_compare = 0;

	for (int i = 0; i < n; i++) {
		sum_move += move_insert[i];
		sum_compare += compare_insert[i];
	}

	average_move_insert = sum_move / 20;
	average_compare_insert = sum_compare / 20;

	// 버블 정렬 반복 시행

	for (int i = 1; i < MAX_SIZE; i++) {
		move_count = 0;
		compare_count = 0;

		for (int i = 0; i < n; i++) {
			list[i] = rand() % 100;
		}

		bubble_sort(list, n, &move_count, &compare_count, 0);

		move_bubble[i] = move_count;
		compare_bubble[i] = compare_count;
	}

	// 이동횟수,비교횟수 합 변수 초기화
	sum_move = 0;
	sum_compare = 0;

	for (int i = 0; i < n; i++) {
		sum_move += move_bubble[i];
		sum_compare += compare_bubble[i];
	}

	average_move_bubble = sum_move / 20;
	average_compare_bubble = sum_compare / 20;

	// 평균 출력
	printf("\n각 정렬별 평균 횟수\n");
	printf("선택 정렬 평균 이동 횟수 : %f\n", average_move_sel);
	printf("선택 정렬 평균 비교 횟수 : %f\n\n", average_compare_sel);
	printf("삽입 정렬 평균 이동 횟수 : %f\n", average_move_insert);
	printf("삽입 정렬 평균 비교 횟수 : %f\n\n", average_compare_insert);
	printf("버블 정렬 평균 이동 횟수 : %f\n", average_move_bubble);
	printf("버블 정렬 평균 비교 횟수 : %f\n\n", average_compare_bubble);

	return 0;
}