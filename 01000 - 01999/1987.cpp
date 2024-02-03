#include <iostream>
using namespace std;

int R, C, mx;
char arr[20][20];
bool check[26];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int cnt, int x, int y);

void dfs(int cnt, int x, int y) {
    mx = max(mx, cnt);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < C && ny >= 0 && ny < R) {
            int nc = arr[ny][nx] - 'A';

            if (!check[nc]) {
                check[nc] = true;
                dfs(cnt + 1, nx, ny);
                check[nc] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) cin >> arr[i][j];

    check[arr[0][0] - 'A'] = true;
    dfs(1, 0, 0);

    cout << mx << '\n';

    return 0;
}