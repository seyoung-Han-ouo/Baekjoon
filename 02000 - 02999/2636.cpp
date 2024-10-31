#include <iostream>
#include <queue>
using namespace std;

int Y, X;
int arr[102][102];
queue<pair<int, int>> cheese;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool check(int y, int x, int num);
void bfs(int sy, int sx);
int melt();

bool check(int y, int x, int num) {
    return y >= 0 && y < Y + 2 && x >= 0 && x < X + 2 && arr[y][x] == num;
}

void bfs(int sy, int sx) {
    queue<pair<int, int>> q;
    q.push({ sy, sx });
    arr[sy][sx] = 2;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (check(ny, nx, 0)) {
                arr[ny][nx] = 2;
                q.push({ ny, nx });
            }
        }
    }
}

int melt() {
    queue<pair<int, int>> q;
    int cheeseCnt = cheese.size();

    for (int i = 0; i < cheeseCnt; i++) {
        int y = cheese.front().first;
        int x = cheese.front().second;
        cheese.pop();

        bool meetAir = false;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (check(ny, nx, 2)) {
                meetAir = true;
                break;
            }
        }

        if (meetAir) q.push({ y, x });
        else cheese.push({ y, x });
    }

    while (!q.empty()) {
        bfs(q.front().first, q.front().second);
        q.pop();
    }

    return cheeseCnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> Y >> X;
    for (int i = 1; i <= Y; i++) {
        for (int j = 1; j <= X; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 1) cheese.push({ i, j });
        }
    }

    bfs(0, 0);

    int time = 0;
    int cheeseCnt = 0;

    while (!cheese.empty()) {
        cheeseCnt = melt();
        time++;
    }

    cout << time << '\n' << cheeseCnt << '\n';

    return 0;
}