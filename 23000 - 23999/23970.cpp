#include <iostream>
#include <algorithm>
using namespace std;

int* A, * B;

// 버블 정렬
int bubble_sort(int N) {
	// 정렬 전 배열 비교
	if (equal(A, A + N, B)) return 1;

	// 배열을 오름차순 정렬한다.
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			// 원소 교환
			if (A[j] > A[j + 1]) {
				int tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;

				// A와 B 비교
				if (A[j] == B[j])
					if (equal(A, A + N, B)) return 1;
			}
		}
	}

	return 0;
}


int main() {
	int N; // 배열의 크기 N
	cin >> N;

	A = new int[N];
	B = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (int i = 0; i < N; i++)
		scanf("%d", &B[i]);

	// 출력
	printf("%d\n", bubble_sort(N));

	delete[] A;
	delete[] B;

	return 0;
}