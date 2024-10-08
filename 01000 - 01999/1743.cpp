#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
int arr[101][101];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs(int sy, int sx);

int bfs(int sy, int sx) {
	int cnt = 1;
	queue<pair<int, int>> q;

	q.push({ sy, sx });
	arr[sy][sx] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny > N || nx < 0 || nx > M) continue;

			if (arr[ny][nx] == 1) {
				cnt++;
				arr[ny][nx] = 0;

				q.push({ ny, nx });
			}
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;

		arr[r][c] = 1;
	}

	int result = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == 1) result = max(result, bfs(i, j));
		}
	}

	cout << result << '\n';

	return 0;
}