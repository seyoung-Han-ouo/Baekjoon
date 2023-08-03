#include <iostream>
using namespace std; 

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int end = M * N / gcd(M, N);
		int i;

		for (i = x; i <= end; i += M) {
			int Y = (i % N == 0) ? N : i % N;

			if (Y == y) {
				cout << i << '\n';
				break;
			}
		}

		if (i > end) cout << "-1\n";
	}

	return 0;
}