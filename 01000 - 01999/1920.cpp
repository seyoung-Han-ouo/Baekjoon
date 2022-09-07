#include <iostream>
#include <algorithm>
using namespace std;

int A[100000] = {};

// 이분탐색
int binarySearch(int key, int low, int high) {
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;

		if (key == A[mid]) // 존재함
			return 1;
		else if (key > A[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return 0; // 존재하지 않음
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	sort(A, A + N); // 정렬

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);

		printf("%d\n", binarySearch(num, 0, N - 1));
	}

	return 0;
}