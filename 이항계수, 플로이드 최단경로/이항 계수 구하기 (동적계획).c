#include <stdio.h>

int bin2(int n, int k) {
	int arr[n+1][k+1];

	for (int i = 0; i <= n + 1; i++) {
		int min = (i < k) ? i : k;

		for (int j = 0; j <= min; j++) {
			if (j == 0 || j == i)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
		}
	}

	return arr[n][k];
}

int main() {
	printf("7C3 = %d\n", bin2(7, 3));

	return 0;
}
