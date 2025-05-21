#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		int mn = 1000000;
		int mx = -1000000;

		while (N--) {
			int n;
			cin >> n;

			mn = min(mn, n);
			mx = max(mx, n);
		}

		cout << mn << ' ' << mx << '\n';
	}

	return 0;
}