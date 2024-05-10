#include <iostream>
#include <vector>
using namespace std;

int arr[1000];
vector<int> dp[1000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int idx = 0, mx = 0;

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i].size() < dp[j].size() + 1) {
				dp[i] = dp[j];
				dp[i].push_back(arr[j]);
			}
		}

		if (mx < dp[i].size()) {
			idx = i;
			mx = dp[i].size();
		}
	}

	cout << mx + 1 << '\n';
	for (int n : dp[idx]) cout << n << ' ';
	cout << arr[idx] << '\n';

	return 0;
}