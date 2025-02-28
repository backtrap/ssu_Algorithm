#include <stdio.h>

void quickSort(int arr[], int low, int high);

int main() {
	int arr[20] = {12, 51, 87, 35, 21, 5, 9, 5, 29, 10, 300, 29, 10, 20, 51, 1, 45, 78, 30, 2};
	
	printf("정렬 전: ");
	for (int i = 0; i < 20; i++)
		printf("%d ", arr[i]);
	printf("\n");

	quickSort(arr, 0, 19);
	
	printf("정렬 후: ");
	for (int i = 0; i < 20; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

void quickSort(int arr[], int low, int high) {
	if (low >= high)
		return;

	int pivotPoint = low;
	int pivotNext = low + 1; // left -> pivotNext
	int ceiling = high;	  // right -> ceiling
	int temp;

	while (pivotNext <= ceiling) {
		while (pivotNext <= high && arr[pivotNext] <= arr[pivotPoint])
			pivotNext++;
		while (ceiling >= low && arr[ceiling] > arr[pivotPoint])
			ceiling--;

		if (pivotNext < ceiling) {
			// Swap elements at pivotNext and ceiling
			temp = arr[pivotNext];
			arr[pivotNext] = arr[ceiling];
			arr[ceiling] = temp;
		}
	}

	// Swap the pivot element with the element at the ceiling index
	temp = arr[pivotPoint];
	arr[pivotPoint] = arr[ceiling];
	arr[ceiling] = temp;

	// Recursive calls for left and right partitions
	quickSort(arr, low, ceiling - 1);
	quickSort(arr, ceiling + 1, high);

	return;
}
