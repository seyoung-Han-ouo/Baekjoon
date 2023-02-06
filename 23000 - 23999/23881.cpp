#include <iostream>
using namespace std;

int N, K; // �迭 A�� ũ�� N, ��ȯ Ƚ�� K

// ���� ����
int selection_sort(int A[]) {
	int count = 0; // ��ȯ Ƚ��

	//A[1..N]�� �������� �����Ѵ�.
	for (int i = N - 1; i > 0; i--) {
		int big = 0;

		// A[]�� ���� ū �� A[]�� ã�´�
		for (int j = 0; j <= i; j++)
			if (A[j] > A[big]) big = j;

		// last�� big�� ���� �ٸ��� A[last]�� A[big]�� ��ȯ
		if (i != big) {
			int tmp = A[i];
			A[i] = A[big];
			A[big] = tmp;

			count++;
		}
		
		// K ��° ��ȯ�Ǵ� �� ���� ��
		if (count == K) {
			printf("%d %d\n", A[big], A[i]);

			return 0;
		}
	}

	return -1;
}

int main() {
	cin >> N >> K;

	int* A = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int num = selection_sort(A);

	// ���
	if (num == -1) printf("-1\n");

	delete[] A;

	return 0;
}