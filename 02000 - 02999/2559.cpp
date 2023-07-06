#include <iostream>
using namespace std;

int arr[100001];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	int big = -10000000; // 온도의 합의 최댓값

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);

		if (i > 0) arr[i] += arr[i - 1];

		// 최댓값 구하기
		if (i >= K - 1) {
			int n = arr[i] - arr[i - K];

			if (n > big) big = n;
		}
	}

	printf("%d\n", big);

	return 0;
}