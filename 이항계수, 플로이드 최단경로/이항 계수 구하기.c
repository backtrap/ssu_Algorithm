#include <stdio.h>

int bin(int n, int k) {
	if (k == 0 || k == n)
		return 1;
	else
		return bin(n - 1, k - 1) + bin(n - 1, k);
}

int main() {
	printf("7C3 = %d\n", bin(7, 3));

	return 0;
}
