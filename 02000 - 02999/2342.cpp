#include <iostream>
#include <cmath>
using namespace std;

#define INF 100000000

int dp[100001][5][5];

void init();
int needPower(int now, int order);

void init() {
	for (int i = 0; i < 100001; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				dp[i][j][k] = INF;
			}
		}
	}

	dp[0][0][0] = 0;
}

int needPower(int now, int order) {
	if (now == 0) return 2;
	if (now == order) return 1;
	if (abs(now - order) == 2) return 4;
	return 3;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	int idx = 0;

	while (true) {
		int order;
		cin >> order;

		if (order == 0) break;

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (dp[idx][i][j] == INF) continue;

				dp[idx + 1][order][j] = min(dp[idx + 1][order][j], dp[idx][i][j] + needPower(i, order));
				dp[idx + 1][i][order] = min(dp[idx + 1][i][order], dp[idx][i][j] + needPower(j, order));
			}
		}

		idx++;
	}

	int result = INF;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			result = min(result, dp[idx][i][j]);
		}
	}

	cout << result << '\n';

	return 0;
}