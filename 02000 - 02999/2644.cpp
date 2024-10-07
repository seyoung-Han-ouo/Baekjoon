#include <iostream>
using namespace std;

int n, m, a, b;
int arr[101][101];
bool check[101];

void dfs(int now, int cnt);

void dfs(int now, int cnt) {
	check[now] = true;

	if (now == a) return;

	for (int i = 1; i <= n; i++) {
		if (arr[i][now] > 0 && !check[i]) {
			arr[i][b] = cnt;

			dfs(i, cnt + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> a >> b >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		arr[x][y] = arr[y][x] = 1;
	}

	dfs(b, 1);

	if (arr[a][b] == 0) cout << "-1\n";
	else cout << arr[a][b] << '\n';

	return 0;
}