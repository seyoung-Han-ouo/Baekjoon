#include <iostream>
using namespace std;

int N;
int result[9];
bool check[9] = { false };

void dfs(int dth) {
	if (dth == N) {
		for (int i = 0; i < N; i++) 
			cout << result[i] << ' ';
		cout << '\n';

		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			result[dth] = i;

			check[i] = true;
			dfs(dth + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	dfs(0);

	return 0;
}