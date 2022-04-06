#include <iostream>
using namespace std;

int arr[7];
int visited[7] = {0};

// 1부터 N까지 자연수 중에서 M개를 고른 수열 찾기
void sequence(int N, int M, int count) {
	// 출력
	if (count == M) {
		for (int i = 0; i < M; i++)
				printf("%d ", arr[i] + 1);

		printf("\n");
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