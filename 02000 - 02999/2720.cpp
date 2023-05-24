#include <iostream>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int num;
		int Q, D, N, P;

		scanf("%d", &num);

		Q = num / 25;
		num %= 25;
		D = num / 10;
		num %= 10;
		N = num / 5;
		num %= 5;
		P = num;

		printf("%d %d %d %d\n", Q, D, N, P);
	}

	return 0;
}