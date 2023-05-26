#include <iostream>
using namespace std;

int arr[101];

// 점수를 몇 번 감소시키면 되는지 찾기
int levelScore(int N) {
	int result = 0;

	for (int i = N - 2; i >= 0; i--) {
		if (arr[i] >= arr[i + 1]) { // 레벨을 감소시켜야 하는 부분
			result += (arr[i] - (arr[i + 1] - 1));
			arr[i] = (arr[i + 1] - 1);
		}
	}

	return result;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	printf("%d\n", levelScore(N));

	return 0;
}