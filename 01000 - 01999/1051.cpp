#include <iostream>
using namespace std;

int main() {
	string nemo[51];

	int N, M; // N×M크기의 직사각형
	cin >> N >> M;

	// 입력
	for (int i = 0; i < N; i++)
		cin >> nemo[i];

	int nemoSize = 1; // 네모의 크기

	// 꼭짓점에 쓰여 있는 수가 모두 같은 가장 큰 정사각형을 찾기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c1 = nemo[i][j]; // 정사각형의 왼쪽 위 꼭짓점

			for (int k = j + 1; k < M; k++) {
				char c2 = nemo[i][k]; // 정사각형의 오른쪽 위 꼭짓점

				if (c1 == c2) {
					int idx = k - j; // 정사각형의 윗꼭짓점 사이의 거리

					// 범위를 벗어남
					if (idx + i >= N) break;

					// 전에 찾았던 것보다 큰 정사각형을 찾음
					if (nemo[idx + i][j] == c1 && nemo[idx + i][k] == c2 && idx + 1 > nemoSize)
						nemoSize = idx + 1;
				}
			}
		}
	}

	// 출력
	printf("%d\n", nemoSize * nemoSize);

	return 0;
}