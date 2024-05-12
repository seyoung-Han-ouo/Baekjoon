#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct Coordinate {
	int x;
	int y;
};

int N, result;
int eatCnt, babySize = 2;
Coordinate baby;
int arr[20][20];
int visit[20][20];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

bool compare(pair<int, Coordinate> a, pair<int, Coordinate> b);
bool eatFish(vector<pair<int, Coordinate>> eat);
bool bfs();

// 상어의 위치와 가깝고, 가장 위, 가장 왼쪽에 있는 순으로 정렬
bool compare(pair<int, Coordinate> a, pair<int, Coordinate> b) {
	if (a.first == b.first) {
		if (a.second.y == b.second.y) {
			return a.second.x < b.second.x;
		}

		return a.second.y < b.second.y;
	}

	return a.first < b.first;
}

// 상어가 먹을 물고기 정하기
bool eatFish(vector<pair<int, Coordinate>> eat) {
	if (eat.empty()) return false;
	else {
		sort(eat.begin(), eat.end(), compare);

		eatCnt++;
		result += eat[0].first;

		baby = eat[0].second;
		arr[eat[0].second.y][eat[0].second.x] = 0;

		return true;
	}
}

bool bfs() {
	memset(visit, 0, sizeof(visit));

	queue<Coordinate> q;
	vector<pair<int, Coordinate>> eat;

	q.push(baby);
	visit[baby.y][baby.x] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int time = visit[y][x];

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int fishSize = arr[ny][nx];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && visit[ny][nx] == 0 && fishSize <= babySize) {
				if (fishSize > 0 && fishSize < babySize)
					eat.push_back({ time, { nx, ny } });
				else {
					q.push({ nx, ny });
					visit[ny][nx] = time + 1;
				}
			}
		}
	}

	return eatFish(eat);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 9) {
				baby = { j, i };
				arr[i][j] = 0;
			}
		}
	}

	while (true) {
		if (!bfs()) break;

		// 상어의 성장
		if (eatCnt == babySize) {
			eatCnt = 0;
			babySize++;
		}
	}

	cout << result << '\n';

	return 0;
}