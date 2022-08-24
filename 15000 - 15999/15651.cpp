#include <iostream>
using namespace std;

int arr[7];
int visited[7] = {0};

// 1���� N���� �ڿ��� �߿��� M���� �� ���� ã��
void sequence(int N, int M, int count) {
	// ���
	if (count == M) {
		for (int i = 0; i < M; i++)
				printf("%d ", arr[i] + 1);

		printf("\n");
	}
	// ���� ã��
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
	// �ڿ��� N�� M
	int N, M;
	cin >> N >> M;

	sequence(N, M, 0);

	return 0;
}