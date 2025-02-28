#include <stdio.h>

void floyd(int n, const int W[n][n], int D[n][n]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			D[i][j] = W[i][j];

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int min = (D[i][j] < D[i][k] + D[k][j]) ? D[i][j] : D[i][k] + D[k][j];
				D[i][j] = min;
			}
		}
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
    int D[4][4]; // 결과를 저장할 매트릭스

    printf("Initial graph (with 9999 as unreachable paths):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (W[i][j] == 9999)
                printf("%4s", "9999");
            else
                printf("%4d", W[i][j]);
        }
        printf("\n");
    }

    // Floyd 알고리즘 실행
    floyd(4, W, D);

    // 최단 경로 출력
    printf("\nShortest paths between each pair of vertices:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (D[i][j] == 9999)
                printf("%4s", "9999");
            else
                printf("%4d", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}
