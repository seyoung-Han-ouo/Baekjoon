#include <iostream>
using namespace std;

char result(int n);

char result(int n) {
	if (n == 3) return 'A';
	if (n == 2) return 'B';
	if (n == 1) return 'C';
	if (n == 0) return 'D';
	if (n == 4) return 'E';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 3; i++) {
		int cnt = 0;

		for (int j = 0; j < 4; j++) {
			int n;
			cin >> n;

			cnt += n;
		}

		cout << result(cnt) << '\n';
	}

	return 0;
}