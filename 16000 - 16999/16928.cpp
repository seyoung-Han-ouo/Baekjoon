#include <iostream>
#include <queue>
using namespace std;

int arr[101];
bool check[101];

void bfs() {
    queue<pair<int, int>> q;

    q.push({ 1, 0 });
    check[1] = true;

    while (!q.empty()) {
        int curx = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int nx = curx + i;

            if (nx == 100) {
                cout << cnt + 1 << '\n';
                return;
            }
            else if (nx < 100) {
                if (arr[nx] != 0) nx = arr[nx];

                if (!check[nx]) {
                    q.push({ nx, cnt + 1 });
                    check[nx] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N + M; i++) {
        int x, y;
        cin >> x >> y;

        arr[x] = y;
    }

    bfs();

    return 0;
}