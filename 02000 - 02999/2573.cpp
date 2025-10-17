#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int N, M;
int arr[301][301];
bool check[301][301];

queue<pair<pair<int, int>, int>> melt;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool canVisit(int y, int x);
void meltIce();
void bfs(int sy, int sx);

// 방문 가능 여부 확인
bool canVisit(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M && !check[y][x];
}

// 빙산 녹이기
void meltIce() {
	while (!melt.empty()) {
		int y = melt.front().first.first;
		int x = melt.front().first.second;
		int cnt = melt.front().second;
		melt.pop();

		arr[y][x] -= cnt;
		if (arr[y][x] < 0) arr[y][x] = 0;
	}
}

// 너비우선탐색
void bfs(int sy, int sx) {
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	check[sy][sx] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			// 방문 가능한 칸이고
			if (canVisit(ny, nx)) {
				if (arr[ny][nx] == 0) cnt++; // 해당 칸이 바다일 때
				else {						 // 해당 칸이 빙산일 때
					check[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
		}

		// 해당 칸에서 녹는 빙산의 양
		melt.push({ { y, x }, cnt });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}

	int year = 0;

	while (true) {
		int cnt = 0; // 빙산의 수

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] > 0 && !check[i][j]) {
					bfs(i, j); 
					cnt++;
				}
			}
		}
		
		// 두 덩어리 이상 빙산이 있을 때
		if (cnt >= 2) break;

		// 빙산이 모두 녹아서 없을 때
		if (cnt == 0) {
			cout << "0\n";
			return 0;
		}

		meltIce();
		memset(check, false, sizeof(check));

		year++;
	}

	cout << year << '\n';

	return 0;
}