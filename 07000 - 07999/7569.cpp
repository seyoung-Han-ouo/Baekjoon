#include <iostream>
#include <queue>
using namespace std;

int N, M, H;
int arr[100][100][100];

int dh[6] = { 0, 0, 0, 0, 1, -1 };
int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
queue<pair<int, pair<int, int>>> q;

void bfs() {
	while (!q.empty()) {
		int curh = q.front().first;
		int curx = q.front().second.first;
		int cury = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int h = curh + dh[i];
			int x = curx + dx[i];
			int y = cury + dy[i];

			if (h >= 0 && h < H && x >= 0 && x < N && y >= 0 && y < M) {
				if (arr[h][x][y] == 0) {
					arr[h][x][y] = arr[curh][curx][cury] + 1;
					q.push({ h, { x, y } });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> arr[i][j][k];

				if (arr[i][j][k] == 1) q.push({ i, {j, k} });
			}
		}
	}

	bfs();

	int result = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[i][j][k] == 0) {
					cout << "-1\n";
					return 0;
				}

				result = max(result, arr[i][j][k]);
			}
		}
	}

	cout << result - 1 << '\n';
	
	return 0;
}