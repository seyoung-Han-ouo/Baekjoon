#include <iostream>
using namespace std;

int bubble_sort(int A[]);

int N, K; // 배열 A의 크기 N, 교환 횟수 K

// 버블 정렬 
int bubble_sort(int A[]) {
	int count = 0; // 교환 횟수

	//A[1..N]을 오름차순 정렬한다.
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			// 원소 교환
			if (A[j] > A[j + 1]) {
				int tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp;

				count++;
			}

			// K 번째 교환되는 수의 인덱스
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

	// 출력
	if (num == -1)
		printf("-1\n");
	else
		for (int i = 0; i < N; i++)
			printf("%d ", A[i]);

	delete[] A;

	return 0;
}