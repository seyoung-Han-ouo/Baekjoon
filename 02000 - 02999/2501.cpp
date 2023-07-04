#include <iostream>
using namespace std;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (N % i == 0) cnt++;

		if (cnt == K) {
			printf("%d\n", i);
			break;
		}
	}

	if (cnt < K) printf("0\n");

	return 0;
}