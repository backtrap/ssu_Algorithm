#include <stdio.h>

int binSearch(const int arr[], int low, int high, int key) {
	if (low > high)
		return -1;

	int mid = (low + high) / 2;

	if (arr[mid] == key)
		return mid;
	else if (arr[mid] < key)
		return binSearch(arr, mid + 1, high, key); // mid + 1부터 탐색
	else
		return binSearch(arr, low, mid - 1, key); // mid - 1까지 탐색
}

int main() {
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int key;
	printf("찾고자 하는 숫자 입력 : ");
	scanf("%d", &key);

	// 인덱스는 0에서 9까지 지정
	int index = binSearch(arr, 0, 9, key);

	if (index == -1)
		printf("배열에 없는 숫자입니다.\n");
	else
		printf("해당 숫자는 %d에 위치합니다.\n", index);

	return 0;
}
