#include <iostream>
#include <string.h>
using namespace std;

int N, mx = 1;
int arr[101][101];
bool check[101][101];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y, int h);
void solve(int h);

void dfs(int x, int y, int h) {
    check[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

        if (!check[nx][ny] && arr[nx][ny] > h) dfs(nx, ny, h);
    }
}

void solve(int h) {
    memset(check, false, sizeof(check));

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!check[i][j] && arr[i][j] > h) {
                dfs(i, j, h);
                cnt++;
            }
        }
    }

    mx = max(mx, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int high = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];

            high = max(high, arr[i][j]);
        }
    }

    for (int i = 1; i <= high; i++) solve(i);

    cout << mx << '\n';

    return 0;
}