#include <stdio.h>

int binSearch(int arr[], int size, int key) {
	int low = 0;
	int high = size - 1;
	int index = 0;
	int mid;

	while (low <= high && index == 0) {
		mid = (low + high)/2;

		if (arr[mid] == key)
			return key;
		else if (arr[mid] < key)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
}

int main() {
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int key;
	printf("찾고자 하는 숫자 입력 : ");
	scanf("%d", &key);

	int index = binSearch(arr, 10, key);

	if (index == -1)
		printf("배열에 없는 숫자입니다.\n");
	else
		printf("해당 숫자는 %d에 위치합니다.\n", index);

	return 0;
}
