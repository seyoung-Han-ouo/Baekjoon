#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < M; j++) arr[i][j] = s[j] - '0';
	}

	q.push({ 0, 0 });

	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = curx + dx[i];
			int y = cury + dy[i];

			if (x >= 0 && x < N && y >= 0 && y < M) {
				if (arr[x][y] == 1) {
					arr[x][y] = arr[curx][cury] + 1;
					q.push({ x, y });
				}
			}
		}
	}

	cout << arr[N - 1][M - 1] << '\n';

	return 0;
}