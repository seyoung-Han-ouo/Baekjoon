#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int N, M, num, mx;
int arr[8][8];
bool check[8][8];
vector<pair<int, int>> virus;

queue<pair<int, int>> q;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool canVisit(int x, int y);
void bfs();
void dfs(int x, int y, int cnt);

// 방문 가능 여부
bool canVisit(int x, int y) {
    return x >= 0 && x < M&& y >= 0 && y < N&& arr[y][x] == 0 && !check[y][x];
}

// 바이러스 확산
void bfs() {
    memset(check, false, sizeof(check));

    for (int i = 0; i < virus.size(); i++)
        q.push(virus[i]);

    int cnt = num;

    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (canVisit(nx, ny)) {
                check[ny][nx] = true;
                q.push({ ny, nx });
                cnt--;
            }
        }
    }

    mx = max(mx, cnt);
}

// 3개의 벽을 세우기
void dfs(int x, int y, int cnt) {
    if (cnt == 3) {
        bfs();
        return;
    }

    for (int i = y; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == y && j < x) continue;

            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                dfs(j, i, cnt + 1);
                arr[i][j] = 0;
            }
        }
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

            // 빈 칸의 개수
            if (arr[i][j] == 0) num++;

            // 바이러스의 위치
            if (arr[i][j] == 2) 
                virus.push_back({ i, j });
        }
    }

    num -= 3;

    dfs(0, 0, 0);

    cout << mx << '\n';

    return 0;
}