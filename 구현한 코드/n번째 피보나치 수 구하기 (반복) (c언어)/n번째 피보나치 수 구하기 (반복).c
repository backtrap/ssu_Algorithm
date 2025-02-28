#include <stdio.h>

int fib(int n) {
	if (n <= 1)
		return n;	

	int arr[n+1];
	arr[0] = 0;
	arr[1] = 1;


	for (int i = 2; i < n+1; i++)
		arr[i] = arr[i-1] + arr[i-2];

	return arr[n];
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", fib(n));

	return 0;
}
