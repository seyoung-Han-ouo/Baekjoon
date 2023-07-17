#include <iostream>
#include <algorithm>
using namespace std;

int N, M, idx = 0;
int arr[7];
int result[7];

void dfs(int dth);

void dfs(int dth) {
	if (dth == M) {
		for (int i = 0; i < M; i++) cout << result[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = 0; i < idx; i++) {
		result[dth] = arr[i];

		dfs(dth + 1);
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

	dfs(0);

	return 0;
}