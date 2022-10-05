#include <iostream>
using namespace std;

unsigned int K, N; // 가지고 있는 랜선의 개수 K, 필요한 랜선의 개수 N
unsigned int arr[10000]; // 가지고 있는 랜선들의 길이
unsigned int high, low = 1;

// 이분탐색
int binarySearch() {
	unsigned int cm = 0; // 잘라낸 랜선의 길이

	while (low <= high) {
		unsigned int mid = (low + high) / 2;
		unsigned int num = 0; // 자른 랜선의 수

		for (int i = 0; i < K; i++)
			num += (arr[i] / mid);

		// 자른 랜선의 수를 N과 비교
		if (num >= N) {
			if (cm < mid) cm = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	return cm;
}

int main() {
	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		scanf("%d", &arr[i]);

		// 가장 긴 랜선의 길이 찾기
		if (arr[i] > high)
			high = arr[i];
	}

	// 출력
	cout << binarySearch() << "\n";

	return 0;
}