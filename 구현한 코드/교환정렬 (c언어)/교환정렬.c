#include <stdio.h>

void exchange(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	return ;
}

int main() {
	int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	exchange(arr, 10);

	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);

	return 0;
}
