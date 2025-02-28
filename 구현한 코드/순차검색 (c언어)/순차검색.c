#include <stdio.h>

int seqsearch(int arr [], int size, int key) {
	for (int i = 0; i < size; i++) 
		if (arr[i] == key)
			return i;
	
	return -1;
}

int main() {
	int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	int key;
	printf("찾고자 하는 숫자 입력 : ");
	scanf("%d", &key);

	int index = seqsearch(arr, 10, key);

	if (index == -1)
		printf("배열에 없는 숫자입니다.\n");
	else
		printf("해당 숫자는 %d에 위치합니다.\n", index);

	return 0;
}

