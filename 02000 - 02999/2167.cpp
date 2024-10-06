#include <iostream>
using namespace std;

int N, M, K;
int arr[301][301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];

			arr[i][j] += (arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1]);
		}
	}

	cin >> K;
	while (K--) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;

		cout << arr[x][y] - arr[x][j - 1] - arr[i - 1][y] + arr[i - 1][j - 1] << '\n';
	}

	return 0;
}