#include <stdio.h>

int prod2(int u, int v, int threshold) {
	if (u == 0 || v == 0)
		return 0;

	int u1, u2, v1, v2;
	int r, p, q;
	int n;
	int m;

	int digit_u = 0;
	int digit_v = 0;
	int num1 = u;
	int num2 = v;
	while (num1 > 0) {
		num1 /= 10;
		digit_u++;
	}
	while (num2 > 0) {
		num2 /= 10;
		digit_v++;
	}
	if (digit_u > digit_v)
		n = digit_u;
	else
		n = digit_v;

	if (n < threshold)
		return u * v;

	m = n / 2;

	int digit = 1;
	for (int i = 0; i < m; i++)
		digit *= 10;

	u1 = u / digit;
	u2 = u % digit;
	v1 = v / digit;
	v2 = v % digit;

	r = prod2(u1 + u2, v1 + v2, threshold);
	p = prod2(u1, v1, threshold);
	q = prod2(u2, v2, threshold);

	return p * digit * digit + (r - p - q) * digit + q;
}

int main() {
	int num1, num2, threshold;

	printf("두 수를 차례로 입력해주세요 : ");
	scanf("%d %d", &num1, &num2);
	printf("임계점을 입력해주세요 : ");
	scanf("%d", &threshold);

	printf("결과는 %d\n", prod2(num1, num2, threshold));

	return 0;
}
