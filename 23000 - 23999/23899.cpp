#include <iostream>
#include <algorithm>
using namespace std;

int A[10001];
int B[10001];

// ���� ����
int selection_sort(int N) {
	if (equal(A, A + N, B)) return 1;

	//A[1..N]�� �������� �����Ѵ�.
	for (int i = N - 1; i > 0; i--) {
		int big = 0; // A[]�� ���� ū ���� ��ġ
		for (int j = 0; j <= i; j++)
			if (A[j] > A[big]) big = j;

		if (big != i) {
			int tmp = A[i];
			A[i] = A[big];
			A[big] = tmp;
		}

		if (equal(A, A + N, B)) return 1;
	}
	
	return 0;
}


int main() {
	int N; //  �迭�� ũ�� N
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (int i = 0; i < N; i++)
		scanf("%d", &B[i]);

	cout << selection_sort(N) << endl;

	return 0;
}