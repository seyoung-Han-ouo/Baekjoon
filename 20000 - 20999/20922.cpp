#include <iostream>
using namespace std;

int arr[200001];
int cnt[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K, result = 0;

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int idx = 0;

	for (int i = 0; i < N; i++) {
		while (idx < N && cnt[arr[idx]] < K) {
			cnt[arr[idx]]++;
			idx++;
		}

		result = max(result, idx - i);

		if (result == N) break;

		cnt[arr[i]]--;
	}

	cout << result << '\n';

	return 0;
}