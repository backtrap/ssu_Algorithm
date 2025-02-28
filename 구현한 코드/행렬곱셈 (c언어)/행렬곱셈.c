#include <stdio.h>

void matrixmult(const int arr[][3], const int brr[][5], int crr[][5], int n, int k, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			crr[i][j] = 0; // 초기화
			for (int l = 0; l < k; l++) {
				crr[i][j] += arr[i][l] * brr[l][j]; // 누적
			}
		}
	}
}

int main() {
	int arr[2][3] = {{1, 3, 5}, {7, 9, 10}};
	int brr[3][5] = {{9, 8, 7, 3, 2}, {1, 6, 5, 4, 1}, {2, 3, 4, 5, 6}};
	int crr[2][5];

	matrixmult(arr, brr, crr, 2, 3, 5);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", crr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
