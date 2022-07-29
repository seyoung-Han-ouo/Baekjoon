#include <iostream>
using namespace std;

int main() {
	int N, L; // 합 N, 길이 L
	cin >> N >> L;

	int num = 0;
	for (int i = 0; i < L; i++)
		num += i;

	// 입력된 L보다 긴 수열이 필요할 때
	if ((N - num) % L != 0 || (N - num) / L < 0) {
		for (int i = 0; ; i++) {
			num += L;
			L++;

			// 수열이 없을 때
			if (L > 100) {
				L = -1;
				break;
			}

			// 수열을 찾았을 때
			if ((N - num) % L == 0 && (N - num) / L >= 0)
				break;
		}
	}

	// 출력
	if (L == -1)
		printf("-1");
	else
		for (int i = 0; i < L; i++)
			printf("%d ", ((N - num) / L) + i);
	printf("\n");

	return 0;
}