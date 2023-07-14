#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
int result[9];

void dfs(int dth);

void dfs(int dth) {
	if (dth == M) {
		for (int i = 0; i < M; i++) cout << result[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = 0; i < N; i++) {
		result[dth] = arr[i];

		dfs(dth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	dfs(0);

	return 0;
}