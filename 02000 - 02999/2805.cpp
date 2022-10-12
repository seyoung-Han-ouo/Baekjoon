#include <iostream>
using namespace std;

unsigned int N, M; // 나무의 수 N, 가져가려고 하는 나무의 길이 M
unsigned int tree[1000001]; // 나무의 높이
unsigned int high = 1, low = 1;

// 이분탐색
int binarySearch() {
	unsigned int treeM = 0;

	while (low <= high) {
		unsigned int mid = (low + high) / 2;
		unsigned int sum = 0;

		// 현재 mid로 잘라낸 나무들의 길이 구하기
		for (int i = 0; i < N; i++) {
			if (tree[i] > mid)
				sum += (tree[i] - mid);

			// 이미 필요한 만큼 잘랐을 때
			if (sum > M) break;
		}

		// sum의 결과에 따라 범위 재설정
		if (sum >= M) {
			low = mid + 1;

			if (treeM < mid)
				treeM = mid;
		}
		else
			high = mid - 1;
	}

	return treeM;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		scanf("%d", &tree[i]);

		// 가장 큰 나무의 길이
		if (high < tree[i])
			high = tree[i];
	}

	// 출력
	cout << binarySearch() << endl;

	return 0;
}