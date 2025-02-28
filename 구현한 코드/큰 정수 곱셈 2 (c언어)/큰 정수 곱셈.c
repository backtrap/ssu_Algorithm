#include <stdio.h>

int prod(int u, int v, int threshold) {
	int u1, u2, v1, v2;
	int n;
	int m;

	int num1 = u;
	int num2 = v;
	int count_u = 0; // u 자리수 확인 용
	int count_v = 0; // v 자리수 확인 용

	// 자리수 계산
	while (num1 > 0) {
		num1 /= 10;
		count_u++;
	}
	while (num2 > 0) {
		num2 /= 10;
		count_v++;
	}

	// 최대 자리수 결정
	n = (count_u > count_v) ? count_u : count_v;

	m = n / 2; // 반으로 나누기
	int ten = 1;

	// 10의 m 제곱 계산
	for (int i = 0; i < m; i++)
		ten *= 10;

	// 기본 조건 처리
	if (u == 0 || v == 0)
		return 0;
	else if (n <= threshold)
		return u * v;
	else {
		// u와 v를 두 개의 부분으로 나누기
		u1 = u / ten; // 고위수
		u2 = u % ten; // 저위수
		v1 = v / ten; // 고위수
		v2 = v % ten; // 저위수

		// 각 부분의 곱을 계산하여 반환
		return prod(u1, v1, threshold) * ten * ten + 
			   prod(u1, v2, threshold) * ten + 
			   prod(u2, v1, threshold) * ten + 
			   prod(u2, v2, threshold);
	}
}

int main() {
	printf("12345 * 12345 = %d\n", prod(12345, 12345, 2));
	printf("123456 * 987654 = %d\n", prod(123456, 987654, 2));

	return 0;
}
