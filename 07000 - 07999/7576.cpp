#include <iostream>
#include <queue>
using namespace std;

int arr[1000][1000];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
queue<pair<int, int>> q;

void bfs(int M, int N);

void bfs(int M, int N) {
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = curx + dx[i];
			int y = cury + dy[i];

			if (x >= 0 && x < N && y >= 0 && y < M) {
				if (arr[x][y] == 0) {
					arr[x][y] = arr[curx][cury] + 1;
					q.push({ x, y });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int M, N, result = 0;
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 1) q.push({ i, j });
		}
	}

	bfs(M, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				cout << "-1\n";
				return 0;
			}

			result = max(result, arr[i][j]);
		}
	}

	cout << result - 1 << '\n';

	return 0;
}