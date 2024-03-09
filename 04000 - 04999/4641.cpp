#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		int n, cnt = 0;
		bool arr[101] = { false };

		while (true) {
			cin >> n;

			if (n == 0 || n == -1) break;

			arr[n] = true;
		}

		if (n == -1) break;

		for (int i = 1; i < 51; i++) {
			if (arr[i] && arr[i * 2]) cnt++;
		}

		cout << cnt << '\n';
	}

	return 0;
}