#include <iostream>
using namespace std;

int n, m, arr[2001];
bool dp[2001][2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		if (arr[i] == arr[i - 1]) dp[i - 1][i] = true;
		dp[i][i] = true;
	}
	cin >> m;

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 2; j <= n; j++) {
			if (arr[i] == arr[j] && dp[i + 1][j - 1]) dp[i][j] = true;
		}
	}

	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}

	return 0;
}