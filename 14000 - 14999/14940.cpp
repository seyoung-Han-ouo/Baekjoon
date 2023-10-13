#include <iostream>
#include <queue>
using namespace std;

int bfs[1001][1001];
queue<pair<int, int>> q;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;

			if (num != 1) {
				bfs[i][j] = 0;

				if (num == 2) q.push({ i, j });
			}
			else bfs[i][j] = -1;
		}
	}

	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = curx + dx[i];
			int y = cury + dy[i];

			if (x >= 0 && x < n && y >= 0 && y < m) {
				if (bfs[x][y] == -1) {
					bfs[x][y] = bfs[curx][cury] + 1;
					q.push({ x, y });
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << bfs[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}