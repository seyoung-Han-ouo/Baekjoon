#include <iostream>
#include <algorithm>
using namespace std;

int N, M, idx = 0;
int arr[8];
int result[8];

void dfs(int dth, int now);

void dfs(int dth, int now) {
	if (dth == M) {
		for (int i = 0; i < M; i++) cout << result[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = now; i < idx; i++) {
		result[dth] = arr[i];

		dfs(dth + 1, i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		for (int j = 0; j < i; j++) {
			if (arr[j] == n) {
				n = -1;
				break;
			}
		}

		if (n != -1) arr[idx++] = n;
	}

	sort(arr, arr + idx);

	dfs(0, 0);

	return 0;
}