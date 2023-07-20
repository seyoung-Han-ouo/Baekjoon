#include <iostream>
using namespace std;

int N, S, cnt = 0;
int num[20];

void dfs(int dth, int result, int now);

void dfs(int dth, int result, int now) {
	if (result == S && dth > 0) cnt++;

	if (dth == N) return;

	for (int i = now; i < N; i++)
		dfs(dth + 1, result + num[i], i + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++) cin >> num[i];

	dfs(0, 0, 0);

	cout << cnt << '\n';

	return 0;
}