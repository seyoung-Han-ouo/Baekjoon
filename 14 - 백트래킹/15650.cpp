#include <iostream>
using namespace std;

int arr[8];
bool visited[8] = {false};

// 1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ���� ã��
void sequence(int N, int M, int count, int firstNum) {
	// ���
	if (count == M) {
		for (int i = 0; i < M; i++)
				printf("%d ", arr[i] + 1);

		printf("\n");
	}

	// fistNum�� �̿��ؼ� �����������θ� ������ ã���� �Ѵ�.
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
	// �ڿ��� N�� M
	int N, M;
	cin >> N >> M;

	sequence(N, M, 0, 0);

	return 0;
}