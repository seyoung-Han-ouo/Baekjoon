#include <iostream>
using namespace std;

int N, M, mx = 0;
int arr[500][500];
bool check[500][500];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y, int cnt, int sum);
void garoShape(int x, int y);
void seroShape(int x, int y);

void dfs(int x, int y, int cnt, int sum) {
    if (cnt == 4) {
        mx = max(mx, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M || check[nx][ny]) continue;

        check[nx][ny] = true;
        dfs(nx, ny, cnt + 1, sum + arr[nx][ny]);
        check[nx][ny] = false;
    }
}

void garoShape(int x, int y) {
    int sum = 0;

    for (int i = 0; i < 3; i++) sum += arr[x + i][y];

    if (y - 1 >= 0) mx = max(mx, sum + arr[x + 1][y - 1]);
    if (y + 1 < M) mx = max(mx, sum + arr[x + 1][y + 1]);
}

void seroShape(int x, int y) {
    int sum = 0;

    for (int i = 0; i < 3; i++) sum += arr[x][y + i];

    if (x - 1 >= 0) mx = max(mx, sum + arr[x - 1][y + 1]);
    if (x + 1 < N) mx = max(mx, sum + arr[x + 1][y + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) cin >> arr[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            check[i][j] = true;
            dfs(i, j, 1, arr[i][j]);
            check[i][j] = false;

            if (i + 2 < N) garoShape(i, j);
            if (j + 2 < M) seroShape(i, j);
        }
    }

    cout << mx << '\n';

    return 0;
}