#include <stdio.h>

void floyd2(int n, const int W[n][n], int D[n][n], int P[n][n]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			D[i][j] = W[i][j];
			P[i][j] = 0;
		}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
			}
		}
	}

	return ;
}

void path(int q, int r, int ** P) {
	if (P[q][r] != 0) {
		path(q, P[q][r], P);
		printf("v%d ", P[q][r]);
		path(P[q][r], r, P);
	}

	return ;
}

int main() {
	int W[4][4] = {
		{0, 3, 9999, 7},
		{8, 0, 2, 9999},
		{5, 9999, 0, 1},
		{2, 9999, 9999, 0}
	};
	int D[4][4];  // 최단 경로 행렬
	int P[4][4];  // 경로 행렬

	// 초기 그래프 출력
	printf("Initial graph (with 9999 as unreachable paths):\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (W[i][j] == 9999)
				printf("%4s", "∞");
			else
				printf("%4d", W[i][j]);
		}
		printf("\n");
	}

	// Floyd 알고리즘 실행
	floyd2(4, W, D, P);

	// 최단 경로 행렬 출력
	printf("\nShortest paths between each pair of vertices:\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (D[i][j] == 9999)
				printf("%4s", "∞");
			else
				printf("%4d", D[i][j]);
		}
		printf("\n");
	}

	// 경로 행렬 출력
	printf("\nPath matrix:\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%4d", P[i][j]);
		}
		printf("\n");
	}

	// 특정 경로 출력 (예: v1에서 v4까지의 경로)
	int start = 0;
	int end = 3;
	printf("\nPath from v%d to v%d: v%d ", start + 1, end + 1, start + 1);
	path(start, end, P);
	printf("v%d\n", end + 1);

	return 0;
}