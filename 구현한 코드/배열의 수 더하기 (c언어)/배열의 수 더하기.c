#include <stdio.h>

int sum(const int arr[], int size) {
	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}

	return sum;
}

int main() {
	int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	printf("배열의 합은 %d\n", sum(arr, 10));

	return 0;
}
