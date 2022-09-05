#include <iostream>
using namespace std;

int main() {
	int team[2];

	for (int i = 0; i < 2; i++) {
		int T, F, S, P, C;
		scanf("%d %d %d %d %d", &T, &F, &S, &P, &C);

		team[i] = T * 6 + F * 3 + S * 2 + P + C * 2;
	}

	printf("%d %d", team[0], team[1]);

	return 0;
}