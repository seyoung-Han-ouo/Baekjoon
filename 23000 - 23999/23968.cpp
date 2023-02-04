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

	int idx = bubble_sort(A);

	// ���
	if (idx == -1)
		printf("%d\n", idx);
	else
		printf("%d %d\n", A[idx], A[idx + 1]);

	delete[] A;

	return 0;
}