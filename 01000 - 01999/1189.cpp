#include <iostream>
using namespace std;

int R, C, K, result = 0;
string arr[5];
bool check[5][5];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool isArrive(int x, int y);
bool canVisit(int x, int y);
void dfs(int x, int y, int cnt);

bool isArrive(int x, int y) {
    return (x == C - 1) && (y == 0);
}

bool canVisit(int x, int y) {
    if (x < 0 || x >= C || y < 0 || y >= R) return false;
    if (check[y][x] || arr[y][x] == 'T') return false;
    return true;
}

void dfs(int x, int y, int cnt) {
    if (cnt > K) return;

    if (cnt == K && isArrive(x, y)) {
        result++;

        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (canVisit(nx, ny)) {
            check[ny][nx] = true;
            dfs(nx, ny, cnt + 1);
            check[ny][nx] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> K;
    for (int i = 0; i < R; i++) cin >> arr[i];

    check[R - 1][0] = true;
    dfs(0, R - 1, 1);

    cout << result << '\n';

    return 0;
}