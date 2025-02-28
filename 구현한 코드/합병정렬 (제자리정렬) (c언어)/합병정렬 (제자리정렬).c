#include <stdio.h>

void mergeSort02(int arr[], int low, int high);
void merge02(int arr[], int low, int mid, int high);

int main() {
	int arr[20] = {12, 51, 87, 35, 21, 5, 9, 5, 29, 10, 300, 29, 10, 20, 51, 1, 45, 78, 30, 2};
	
	for (int i = 0; i < 20; i++)
		printf("%d ", arr[i]);
	printf("\n");

	mergeSort02(arr, 0, 19);
	
	for (int i = 0; i < 20; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

void mergeSort02(int arr[], int low, int high) {
	int mid;

	if (low < high) {
		mid = (low + high)/2;

		mergeSort02(arr, low, mid);
		mergeSort02(arr, mid + 1, high);
		merge02(arr, low, mid, high);
	}

	return ;
}

void merge02(int arr[], int low, int mid, int high) {
	int i = low;
	int j = mid + 1;
	int k = 0;
	int temp[high-low+1];

	while (i <= mid && j <= high) {
		if (arr[i] < arr[j]) {
			temp[k] = arr[i];
			i++;
		}
		else {
			temp[k] = arr[j];
			j++;
		}

		k++;
	}

	if (i > mid) {
		while (j <= high)
			temp[k++] = arr[j++];
	}
	else {
		while (i <= high)
			temp[k++] = arr[i++];
	}

	for (i = low, k = 0; i <= high; i++, k++)
		arr[i] = temp[k];

	return ;

}

