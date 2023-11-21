#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n, int* move_count, int* compare_count) {
	int least, temp;

	for (int i = 0; i < n - 1; i++) {
		least = i;
		(*move_count)++;

		for (int k = 0; k < n; k++) {
			printf("%d ", list[k]);
		}
		printf("\n");

		for (int j = i+1; j < n; j++) {
			if (list[j] < list[least]) least = j;
			(*compare_count)++;
		}
		SWAP(list[i], list[least], temp);
	}
}

void insertion_sort(int list[], int n, int* move_count, int* compare_count) {
	int i,j,key;

	for (i = 1; i < n; i++) {
		key = list[i];
		(*move_count)++;

		for (int k = 0; k < n; k++) {
			printf("%d ", list[k]);
		}
		printf("\n");

		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j];
			(*compare_count)++;
		}
		list[j + 1] = key;
	}
}

int main()
{
	n = MAX_SIZE;
	int move_count = 0;
	int compare_count = 0;

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		list[i] = rand() % 100;
	}

	printf("Original List\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n\n");

	//printf("Selection List\n");
	//selection_sort(list, n, &move_count, &compare_count);

	//for (int i = 0; i < n; i++) {
	//	printf("%d ", list[i]);
	//}
	//printf("\n");
	//printf("Move : %d\n", move_count);
	//printf("Compare : %d\n", compare_count);

	//move_count, compare_count = 0;

	printf("\nInsertion List\n");
	insertion_sort(list, n, &move_count, &compare_count);
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
	printf("Move : %d\n", move_count);
	printf("Compare : %d\n", compare_count);

	return 0;
}