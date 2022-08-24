#include <iostream>
using namespace std;

int arr[8];
bool visited[8] = {false};

// 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열 찾기
void sequence(int N, int M, int count, int firstNum) {
	// 출력
	if (count == M) {
		for (int i = 0; i < M; i++)
				printf("%d ", arr[i] + 1);

		printf("\n");
	}

	// fistNum을 이용해서 오름차순으로만 수열을 찾도록 한다.
	for (int i = firstNum; i < N; i++) {
		if (!visited[i]) {
			arr[count] = i;
			visited[i] = true;

			firstNum++;
			sequence(N, M, count + 1, firstNum);

			visited[i] = false;
		}
	}
}

int main() {
	// 자연수 N과 M
	int N, M;
	cin >> N >> M;

	sequence(N, M, 0, 0);

	return 0;
}