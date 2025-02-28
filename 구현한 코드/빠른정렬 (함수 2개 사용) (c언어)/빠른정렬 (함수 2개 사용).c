#include <stdio.h>

void quickSort(int arr[], int low, int high);
void partition(int arr[], int low, int high, int * pivotPoint);

int main() {
	int arr[20] = {12, 51, 87, 35, 21, 5, 9, 5, 29, 10, 300, 29, 10, 20, 51, 1, 45, 78, 30, 2};
	
	for (int i = 0; i < 20; i++)
		printf("%d ", arr[i]);
	printf("\n");

	quickSort(arr, 0, 19);
	
	for (int i = 0; i < 20; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

void quickSort(int arr[], int low, int high) {
	int pivotPoint;

	if (low < high) {
		partition(arr, low, high, &pivotPoint);
		quickSort(arr, low, pivotPoint - 1);
		quickSort(arr, pivotPoint + 1, high);
	}

	return ;
}

void partition(int arr[], int low, int high, int * pivotPoint) {
	int i = low + 1;
	int j = low;
	int pivotItem = arr[low];

	for ( ; i <= high; i++) {
		if (arr[i] < pivotItem) {
			j++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	*pivotPoint = j;

	int temp = arr[low];
	arr[low] = arr[*pivotPoint];
	arr[*pivotPoint] = temp;

	return ;
}
