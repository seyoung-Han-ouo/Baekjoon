#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int S, N, M;
	cin >> S >> N >> M;

	int cnt = 0;
	for (int i = 0; i < N + M; i++) {
		int n;
		cin >> n;

		if (n == 0) cnt--;
		else {
			if (cnt == S) S *= 2;
			cnt++;
		}
	}

	cout << S << '\n';

	return 0;
}