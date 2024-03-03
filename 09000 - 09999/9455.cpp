#include <iostream>
using namespace std;

int arr[100][100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m >> n;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) cin >> arr[i][j];
		}

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			int box = 0;

			for (int j = 0; j < m; j++) {
				if (arr[m - j - 1][i] == 1) {
					cnt += (j - box);
					box++;
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}