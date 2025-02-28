#include <stdio.h>

void bubbleSort(int arr[], int size) {
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	return ;
}

int main() {
	int arr[10] = {10, 8, 6, 4, 2, 1, 3, 5, 7, 9};

	bubbleSort(arr, 10);

	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);

	return 0;
}
