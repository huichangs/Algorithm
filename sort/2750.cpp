#include<stdio.h>
#include<stdlib.h>

int selectSort(int arr[], int size) {
	int i, j, min;
	int temp = 0;
	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
	return 1;
}

int main() {
	int size;

	int i, j;

	scanf("%d", &size);

	int* num = (int*)malloc(sizeof(int) * size);

	for (i = 0; i < size; i++) {
		scanf("%d", &num[i]);
	}

	selectSort(num, size);

	for (i = 0; i < size; i++) {
		printf("%d\n", num[i]);
	}


	return 0;
}
