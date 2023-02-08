#include <iostream>
using namespace std;

int N, K;

int selection_sort(int A[]);

int selection_sort(int A[]) {
	int count = 0; // ��ȯ Ƚ��

	// A[1..N]�� �������� �����Ѵ�.
	for (int i = N - 1; i > 0; i--) {
		int big = 0;

		// A[]�� ���� ū ���� ã�´�
		for (int j = 0; j <= i; j++)
			if (A[j] > A[big]) big = j;

		// last�� big�� ���� �ٸ��� A[last]�� A[big]�� ��ȯ
		if (big != i) {
			int tmp = A[i];
			A[i] = A[big];
			A[big] = tmp;

			count++;
		}

		// K ��° ��ȯ
		if (count == K) {
			for (int j = 0; j < N; j++) // ���
				printf("%d ", A[j]);

			return 0;
		}
	}

	return -1;
}

int main() {
	scanf("%d %d", &N, &K);

	int* A = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	
	// ���
	if (selection_sort(A) == -1)
		printf("-1\n");

	delete[] A;

	return 0;
}