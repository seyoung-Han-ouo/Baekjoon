#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long S, N;
	cin >> S;

	for (N = 1; ; N++) {
		S -= N;

		if (S <= 0) break;
	}

	if (S < 0) N--;

	cout << N << '\n';

	return 0;
}