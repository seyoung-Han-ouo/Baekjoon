#include <iostream>
#include <algorithm>
using namespace std;

int* arr;

// 이분탐색
int binarySearch(int key, int low, int high) {
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;

		if (key == arr[mid]) // 존재함
			return 1;

		// 범위 다시 정하기
		if (key > arr[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}

	return 0; // 존재하지 않음
}

int main() {
	int N; // 상근이가 가지고 있는 숫자 카드의 개수
	cin >> N;

	arr = new int[N];

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + N); // 정렬

	int M; // 찾아야 하는 수의 개수
	cin >> M;

	for (int i = 0; i < M; i++) {
		int num; // 찾아야 하는 수
		scanf("%d", &num);

		// 출력
		printf("%d ", binarySearch(num, 0, N - 1));
	}

	delete[] arr;

	return 0;
}