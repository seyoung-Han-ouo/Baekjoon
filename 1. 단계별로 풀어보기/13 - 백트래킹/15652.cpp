#include <iostream>
using namespace std;

int arr[8];
int visited[8] = {0};

// 1���� N���� �ڿ��� �߿��� M���� �� ���� ã��
void sequence(int N, int M, int count) {
	if (count == M) {
		bool dontPrint = false;
		int a = arr[0];

		// �� ������ �񳻸������̾�� �Ѵ�.
		for (int i = 1; i < M; i++) {
			if (a > arr[i]) {
				dontPrint = true;
				break;
			}

			a = arr[i];
		}

		// ���
		if (dontPrint == false) {
			for (int i = 0; i < M; i++)
				printf("%d ", arr[i] + 1);

			printf("\n");
		}
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