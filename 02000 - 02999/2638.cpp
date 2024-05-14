#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[100][100];
queue<pair<int, int>> cheese;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool check(int nx, int ny, int num);
void bfs(int y, int x);
void melt();

bool check(int nx, int ny, int num) {
	return (nx >= 0 && nx < M&& ny >= 0 && ny < N&& arr[ny][nx] == num);
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	arr[y][x] = 2;

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (check(nx, ny, 0)) {
				q.push({ ny, nx });
				arr[ny][nx] = 2;
			}
		}
	}
}

void melt() {
	queue<pair<int, int>> q;

	int cheeseSize = cheese.size();

	while (cheeseSize--) {
		int x = cheese.front().second;
		int y = cheese.front().first;
		cheese.pop();

		int cnt = 0;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (check(nx, ny, 2)) cnt++;
		}

		if (cnt >= 2) q.push({ y, x });
		else cheese.push({ y, x });
	}

	while (!q.empty()) {
		bfs(q.front().first, q.front().second);

		q.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 1) cheese.push({ i, j });
		}
	}

	bfs(0, 0);

	int time = 0;
	while (cheese.size() > 0) {
		melt();
		time++;
	}

	cout << time << '\n';

	return 0;
}