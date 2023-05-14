#include <iostream>
using namespace std;

int main() {
	int S, K, H;
	scanf("%d %d %d", &S, &K, &H);

	if (S + K + H < 100) {
		if (S < K && S < H)
			printf("Soongsil\n");
		else if (K < S && K < H)
			printf("Korea\n");
		else
			printf("Hanyang\n");
	}
	else
		printf("OK\n");

	return 0;
}