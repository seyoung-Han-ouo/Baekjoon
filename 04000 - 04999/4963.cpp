#include <iostream>
#include <queue>
using namespace std;

int W, H;
int arr[51][51];

int dh[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dw[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };

void bfs(int a, int b);

void bfs(int a, int b) {
    queue<pair<int, int>> q;

    q.push({ a, b });
    arr[a][b] = 0;

    while (!q.empty()) {
        int h = q.front().first;
        int w = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nh = h + dh[i];
            int nw = w + dw[i];

            if (nh >= 0 && nh < H && nw >= 0 && nw < W) {
                if (arr[nh][nw] == 1) {
                    q.push({ nh, nw });
                    arr[nh][nw] = 0;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true) {
        cin >> W >> H;

        if (W == 0 && H == 0) break;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) cin >> arr[i][j];
        }

        int cnt = 0;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (arr[i][j] == 1) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}