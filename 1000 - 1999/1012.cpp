#include <iostream>
#include <cstring>
using namespace std;

int M, N, K; // 가로길이 M, 세로길이 N, 배추가 심어져 있는 위치의 개수 K

bool field[51][51] = { false }; // 배추밭
bool visited[51][51] = { false }; // 방문여부

int x_[4] = { 0, 0, -1, 1 }; // 상하좌우
int y_[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int xx = x + x_[i];
		int yy = y + y_[i];

		if (xx >= 0 && yy >= 0 && xx < M && yy < N) {
			if (field[xx][yy] && !visited[xx][yy])
				dfs(xx, yy); // 재귀
		}
	}
}

int main() {
	int T; // 테스트 케이스의 개수 
	cin >> T;

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &M, &N, &K);

		// 배추 위치 입력
		for (int j = 0; j < K; j++) {
			int x, y;
			scanf("%d %d", &x, &y);

			field[x][y] = true;
		}

		int count = 0; // 벌레의 수

		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (field[j][k] && !visited[j][k]) {
					count++;
					dfs(j, k);
				}
			}
		}

		// 출력
		printf("%d\n", count);

		// 초기화
		memset(field, false, sizeof(field));
		memset(visited, false, sizeof(visited));
	}

	return 0;
}