#include <iostream>
using namespace std;

int main() {
	int T; // 테스트 케이스의 개수
	scanf("%d", &T);

	int arr[11] = { 0, 1, 2, 4, };
	int j = 4;

	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);

		// n을 1, 2, 3의 합으로 나타내는 방법의 수 구하기
		for (j; j <= n; j++)
			arr[j] = arr[j - 3] + arr[j - 2] + arr[j - 1];

		printf("%d\n", arr[n]);
	}

	return 0;
}