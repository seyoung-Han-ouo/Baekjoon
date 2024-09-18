#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[1003][1003];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int x, int y);

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = nowx + dx[i];
			int ny = nowy + dy[i];

			if (nx < 0) nx = M - 1;
			else if (nx >= M) nx = 0;

			if (ny < 0) ny = N - 1;
			else if (ny >= N) ny = 0;

			if (arr[ny][nx] == 0) {
				arr[ny][nx] = 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) cin >> arr[i][j];

	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				result++;

				bfs(j, i);
			}
		}
	}

	cout << result << '\n';

	return 0;
}