#include <iostream>
using namespace std;

int N;
int arr[1000];
int dp[2][1000];

void increase();
void decrease();

void increase() {
	for (int i = 0; i < N; i++) {
		dp[0][i] = 1;

		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp[0][i] = max(dp[0][i], dp[0][j] + 1);
		}
	}
}

void decrease() {
	for (int i = N - 1; i >= 0; i--) {
		dp[1][i] = 1;

		for (int j = N - 1; j > i; j--) {
			if (arr[j] < arr[i])
				dp[1][i] = max(dp[1][i], dp[1][j] + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	increase();
	decrease();

	int result = 0;
	for (int i = 0; i < N; i++)
		result = max(result, dp[0][i] + dp[1][i] - 1);

	cout << result << '\n';

	return 0;
}