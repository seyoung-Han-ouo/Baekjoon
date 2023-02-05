#include <iostream>
using namespace std;

int bubble_sort(int A[]);

int N, K; // �迭 A�� ũ�� N, ��ȯ Ƚ�� K

// ���� ���� 
int bubble_sort(int A[]) {
	int count = 0; // ��ȯ Ƚ��

	//A[1..N]�� �������� �����Ѵ�.
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			// ���� ��ȯ
			if (A[j] > A[j + 1]) {
				int tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp;

				count++;
			}

			// K ��° ��ȯ�Ǵ� ���� �ε���
			if (count == K) return j;
		}
	}

	return -1;
}

int main() {
	cin >> N >> K;

	int* A = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int num = bubble_sort(A);

	// ���
	if (num == -1)
		printf("-1\n");
	else
		for (int i = 0; i < N; i++)
			printf("%d ", A[i]);

	delete[] A;

	return 0;
}