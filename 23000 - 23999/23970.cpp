#include <iostream>
#include <algorithm>
using namespace std;

int* A, * B;

// ���� ����
int bubble_sort(int N) {
	// ���� �� �迭 ��
	if (equal(A, A + N, B)) return 1;

	// �迭�� �������� �����Ѵ�.
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			// ���� ��ȯ
			if (A[j] > A[j + 1]) {
				int tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;

				// A�� B ��
				if (A[j] == B[j])
					if (equal(A, A + N, B)) return 1;
			}
		}
	}

	return 0;
}


int main() {
	int N; // �迭�� ũ�� N
	cin >> N;

	A = new int[N];
	B = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (int i = 0; i < N; i++)
		scanf("%d", &B[i]);

	// ���
	printf("%d\n", bubble_sort(N));

	delete[] A;
	delete[] B;

	return 0;
}