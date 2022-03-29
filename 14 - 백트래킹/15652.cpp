#include <iostream>
using namespace std;

int arr[8];
int visited[8] = {0};

// 1부터 N까지 자연수 중에서 M개를 고른 수열 찾기
void sequence(int N, int M, int count) {
	if (count == M) {
		bool dontPrint = false;
		int a = arr[0];

		// 고른 수열은 비내림차순이어야 한다.
		for (int i = 1; i < M; i++) {
			if (a > arr[i]) {
				dontPrint = true;
				break;
			}

			a = arr[i];
		}

		// 출력
		if (dontPrint == false) {
			for (int i = 0; i < M; i++)
				printf("%d ", arr[i] + 1);

			printf("\n");
		}
	}
	// 수열 찾기
	else {
		for (int i = 0; i < N; i++) {
			if (visited[i] < M) {
				arr[count] = i;
				visited[i]++;

				sequence(N, M, count + 1);

				visited[i]--;
			}
		}
	}
}

int main() {
	// 자연수 N과 M
	int N, M;
	cin >> N >> M;

	sequence(N, M, 0);

	return 0;
}