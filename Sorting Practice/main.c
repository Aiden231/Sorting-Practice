#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int list[MAX_SIZE];
int n;

// ���� ���� �Լ�
void selection_sort(int list[], int n, int* move_count, int* compare_count, int print) {
	int least, temp;

	for (int i = 0; i < n - 1; i++) {
		least = i;
		(*move_count)++;

		// print�� 1�� ��쿡�� ���� ���
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

// ���� ���� �Լ�
void insertion_sort(int list[], int n, int* move_count, int* compare_count, int print) {
	int i,j,key;

	for (i = 1; i < n; i++) {
		key = list[i];
	
		// print�� 1�� ��쿡�� ���� ���� ���
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

// ���� ���� �Լ�
void bubble_sort(int list[], int n, int* move_count, int* compare_cout, int print) {
	int temp;

	for (int i = n - 1; i > 0; i--) {

		// print�� 1�� ��쿡�� ���� ���� ���
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
	// �̵� Ƚ��, �� Ƚ�� ����
	int move_count = 0;
	int compare_count = 0;
	// �̵� Ƚ�� ��, �� Ƚ�� ��
	int sum_move = 0;
	int sum_compare = 0;
	// ���� ���� �̵�, �� Ƚ�� �迭 �� ��հ� ���� ����
	int move_sel[MAX_SIZE] = { 0 };
	int compare_sel[MAX_SIZE] = { 0 };
	double average_move_sel = 0;
	double average_compare_sel = 0;
	// ���� ���� �̵�, �� Ƚ�� �迭 �� ��հ� ���� ����
	int move_insert[MAX_SIZE] = { 0 };
	int compare_insert[MAX_SIZE] = { 0 };
	double average_move_insert = 0;
	double average_compare_insert = 0;
	// ���� ���� �̵�, �� Ƚ�� �迭 �� ��հ� ���� ����
	int move_bubble[MAX_SIZE] = { 0 };
	int compare_bubble[MAX_SIZE] = { 0 };
	double average_move_bubble = 0;
	double average_compare_bubble = 0;

	// ���� ����Ʈ ����
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		list[i] = rand() % 100;
	}

	// ���� ����

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

	// ���� ����

	// �̵� �� �� Ƚ�� �ʱ�ȭ
	move_count = 0;
	compare_count = 0;

	// ���� ����Ʈ ����
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

	// ���� ����

	// �̵� �� �� Ƚ�� �ʱ�ȭ
	move_count = 0;
	compare_count = 0;

	// ���� ����Ʈ ����
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

	// ���� ���� �ݺ� ����

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

	// ���� ���� �ݺ� ����

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

	// �̵�Ƚ��,��Ƚ�� �� ���� �ʱ�ȭ
	sum_move = 0;
	sum_compare = 0;

	for (int i = 0; i < n; i++) {
		sum_move += move_insert[i];
		sum_compare += compare_insert[i];
	}

	average_move_insert = sum_move / 20;
	average_compare_insert = sum_compare / 20;

	// ���� ���� �ݺ� ����

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

	// �̵�Ƚ��,��Ƚ�� �� ���� �ʱ�ȭ
	sum_move = 0;
	sum_compare = 0;

	for (int i = 0; i < n; i++) {
		sum_move += move_bubble[i];
		sum_compare += compare_bubble[i];
	}

	average_move_bubble = sum_move / 20;
	average_compare_bubble = sum_compare / 20;

	// ��� ���
	printf("\n�� ���ĺ� ��� Ƚ��\n");
	printf("���� ���� ��� �̵� Ƚ�� : %f\n", average_move_sel);
	printf("���� ���� ��� �� Ƚ�� : %f\n\n", average_compare_sel);
	printf("���� ���� ��� �̵� Ƚ�� : %f\n", average_move_insert);
	printf("���� ���� ��� �� Ƚ�� : %f\n\n", average_compare_insert);
	printf("���� ���� ��� �̵� Ƚ�� : %f\n", average_move_bubble);
	printf("���� ���� ��� �� Ƚ�� : %f\n\n", average_compare_bubble);

	return 0;
}