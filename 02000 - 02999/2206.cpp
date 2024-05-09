#include <iostream>
#include <queue>
using namespace std;

int N, M;
bool arr[1001][1001];
int visit[1001][1001][2];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs();

int bfs() {
    queue<pair<pair<int, int>, bool>> q;

    q.push({ { 1, 1 }, false });
    visit[1][1][0] = 1;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        bool isBreak = q.front().second;
        int cnt = visit[y][x][isBreak];

        q.pop();

        if (x == M && y == N) return cnt;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= M && ny > 0 && ny <= N) {
                if (!arr[ny][nx] && visit[ny][nx][isBreak] == 0) {
                    q.push({ { nx, ny }, isBreak });
                    visit[ny][nx][isBreak] = cnt + 1;
                }
                else if (arr[ny][nx] && !isBreak) {
                    q.push({ { nx, ny }, true });
                    visit[ny][nx][!isBreak] = cnt + 1;
                }
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++)
            arr[i][j + 1] = (s[j] == '0') ? 0 : 1;
    }

    cout << bfs() << '\n';

    return 0;
}