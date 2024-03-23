#include <iostream>
#include <queue>
using namespace std;

int n, m;
int paper[500][500];

queue<pair<int, int>> q;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs(int a, int b);

int bfs(int a, int b) {
    int cnt = 0;

    q.push({ a, b });
    paper[a][b] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        cnt++;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (paper[nx][ny] == 1) {
                q.push({ nx, ny });
                paper[nx][ny] = 0;
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> paper[i][j];
    }

    int cnt = 0, mx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (paper[i][j] == 1) {
                mx = max(mx, bfs(i, j));
                cnt++;
            }
        }
    }

    cout << cnt << '\n' << mx << '\n';

    return 0;
}