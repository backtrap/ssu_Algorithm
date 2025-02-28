#include <stdio.h>

void mergeSort(int arr[], int size);
void merge(int size01, int size02, const int brr[], const int crr[], int arr[]);

int main() {
	int arr[20] = {12, 51, 87, 35, 21, 5, 9, 5, 29, 10, 300, 29, 10, 20, 51, 1, 45, 78, 30, 2};
	
	for (int i = 0; i < 20; i++)
		printf("%d ", arr[i]);
	printf("\n");

	mergeSort(arr, 20);
	
	for (int i = 0; i < 20; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

void mergeSort(int arr[], int size) {
	if (size > 1) {
		int size01 = size / 2;
		int size02 = size - size01;

		int brr[size01];
		int crr[size02];

		for (int i = 0; i < size01 ; i++)
			brr[i] = arr[i];

		for (int i = 0; i < size02 ; i++) {
			crr[i] = arr[i+size01];
		}

		mergeSort(brr, size01);
		mergeSort(crr, size02);

		merge(size01, size02, brr, crr, arr);
	}

	return ;
}

void merge(int size01, int size02, const int brr[], const int crr[], int arr[]) {
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < size01 && j < size02) {
		if (brr[i] < crr[j]) {
			arr[k] = brr[i];
			i++;
		}
		else {
			arr[k] = crr[j];
			j++;
		}

		k++;
	}

	if (i >= size01) {
		while (j < size02) {
			arr[k] = crr[j];
			k++;
			j++;
		}
	}
	else {
		while (i < size01) {
			arr[k] = brr[i];
			k++;
			i++;
		}
	}

	return ;
}

