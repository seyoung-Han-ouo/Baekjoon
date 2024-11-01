#include <iostream>
using namespace std;

int M, N;
int map[501][501];
int visit[501][501];

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool canVisit(int y, int x);
int dfs(int y, int x);

bool canVisit(int y, int x) {
    return (y >= 0 && y < M && x >= 0 && x < N);
}

int dfs(int y, int x) {
    if (y == M - 1 && x == N - 1) return 1;

    if (visit[y][x] == -1) {
        visit[y][x] = 0;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (canVisit(ny, nx) && map[ny][nx] < map[y][x]) 
                visit[y][x] += dfs(ny, nx);
        }
    }

    return visit[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            visit[i][j] = -1;
        }
    }

    cout << dfs(0, 0) << '\n';

    return 0;
}