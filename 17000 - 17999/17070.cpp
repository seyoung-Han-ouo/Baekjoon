#include <iostream>
using namespace std;

int N;
int arr[16][16];

void dfs(int x, int y, int d);

void dfs(int x, int y, int d) {
    arr[y][x]++;

    int nx = x + 1;
    int ny = y + 1;

    if (d == 0 || d == 2) {
        if (nx < N && arr[y][nx] != -1) dfs(nx, y, 0);
    }

    if (d == 1 || d == 2) {
        if (ny < N && arr[ny][x] != -1) dfs(x, ny, 1);
    }

    if (nx < N && ny < N && arr[y][nx] != -1 && arr[ny][x] != -1 && arr[ny][nx] != -1) dfs(nx, ny, 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 1) arr[i][j] = -1;
        }
    }

    dfs(1, 0, 0);

    if (arr[N - 1][N - 1] == -1) cout << "0\n";
    else cout << arr[N - 1][N - 1] << '\n';

    return 0;
}